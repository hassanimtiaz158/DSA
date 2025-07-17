#include <iostream>
#include <string>
using namespace std;

bool issubstring(const string& small,const string& big){
	return big.find(small)!=string::npos;
}

bool isrotation(const string& s1,const string& s2){
	if(s1.length()!=s2.length() or s2.empty()){
		return false;
	}
	string combine=s1+s1;
	return issubstring(s2,combine);
}

int main(){
	string s1="waterbottle";
	string s2="erbottlewat";
	if(isrotation(s1,s2)){
		cout<<"True";
	}else{
		cout<<"False";
	}
	
	return 0;
}
