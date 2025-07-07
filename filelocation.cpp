#include <iostream>
#include <dirent.h>

using namespace std;

bool findFile(string dir, string target, string& result) {
    DIR* dirp = opendir(dir.c_str());
    if (!dirp) return false;

    dirent* entry;
    while ((entry = readdir(dirp))) {
        string name = entry->d_name;
        if (name == "." || name == "..") continue;

        string path = dir + "/" + name;
        if (name == target && !opendir(path.c_str())) {
            result = path;
            closedir(dirp);
            return true;
        }
        if (opendir(path.c_str()) && findFile(path, target, result)) {
            closedir(dirp);
            return true;
        }
    }
    closedir(dirp);
    return false;
}

int main() {
    string startDir = "D:/Desktop/AI/streamlit", foundPath;
    if (findFile(startDir, "requirements.txt", foundPath))
        cout << "Found: " << foundPath << endl;
    else
        cout << "Not found" << endl;
    return 0;
}
