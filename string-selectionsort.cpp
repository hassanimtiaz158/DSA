#include <iostream>
#include <string>
using namespace std;

void selectionsort(string arr[],int n){
	for(int i=0;i<n;i++){
		int smallindex=i;
		for(int j=i+1;j<n;j++){
			if(arr[j].length()<arr[smallindex].length()){
				smallindex=j;
			}
		}
		swap(arr[i],arr[smallindex]);
		cout<<"Pass "<<i+1<<": ";
		for(int k=0;k<n;k++){
			cout<<arr[k]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	string arr[]={"hasan","ali","Sameer","hamza"};
	int n=sizeof(arr)/sizeof(arr[0]);
	selectionsort(arr,n);
	
	cout<<"Sorted Array: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}


