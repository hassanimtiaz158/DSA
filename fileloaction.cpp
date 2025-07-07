#include <iostream>
#include <filesystem>
#include <string>

using namespace std;

bool findFile(const filesystem::path& dir, const string& target, filesystem::path& result) {
    try {
        for (const auto& entry : filesystem::recursive_directory_iterator(dir, filesystem::directory_options::skip_permission_denied)) {
            if (entry.is_regular_file() && entry.path().filename() == target) {
                result = entry.path();
                return true;
            }
        }
    } catch (const filesystem::filesystem_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return false;
}

int main() {
    string filename = "Resume.pdf";
    filesystem::path startDir = "D:\\Desktop\\Doc"; 
    filesystem::path foundPath;

    if (findFile(startDir, filename, foundPath)) {
        cout << "File found at: " << foundPath << endl;
    } else {
        cout << "File not found." << endl;
    }

    return 0;
}
