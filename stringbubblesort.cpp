#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

bool caseinsensitivitycomparator(char a,char b){
	return tolower(a)>tolower(b);
}

void bubblesort(string&str){
	int n=str.length();
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(caseinsensitivitycomparator(str[j],str[j+1])){
				std::swap(str[j],str[j+1]);
			}
		}
	}
	cout<<str<<"";
}

int main(){
	string str="HasanALi";
	bubblesort(str);
	
	return 0;
}


