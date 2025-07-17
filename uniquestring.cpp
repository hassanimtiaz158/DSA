#include <iostream>
using namespace std;

bool uniquestring(string s){
	int n=s.length();
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[j]>s[j+1]){
				swap(s[j],s[j+1]);//sort
			}
			if(s[j]==s[j+1]){//check uniqueness
				return true;
			}
		}
	}
	return false;
}

int main(){
	string s="Hasn";
	if(uniquestring(s)==1){
		cout<<"False";
	}else{
		cout<<"True";
	}
	
	return 0;
}
