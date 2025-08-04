#include <iostream>
#include <list>
#include <utility>
using namespace std;

const int table_size=10;

class hashtable{
	private:
	    list<pair<int,string>> Table[table_size];
	    int hashfunction(int key){
	    	return key%table_size;
		}
	public:
		void insert(int key,const string& value){
			int index=hashfunction(key);
			for(auto& entry:Table[index]){
				if(entry.first==key){
					entry.second=value;
					return;
				}
			}
			Table[index].push_back({key,value});
		}
		bool search(int key){
		}
		void del(int key){
		}
		void display(){
			for(int i=0;i<table_size;i++){
				cout<<i<<" : ";
				for(auto& entry:Table[i]){
					cout<<"["<<i.first<<","<<i.second<<"]"<<endl;
				}
			}
			
		}
};

int main(){
	hashtable h;
	h.insert(1,"Hasan");
	
	return 0;
}
