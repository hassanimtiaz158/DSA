#include <iostream>
using namespace std;

void insertionsort(int arr[],int n){
	for(int i=1;i<n;i++){
		int key=arr[i];
		int j=i-1;
		while(j>=0 and arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[5]={7,3,5,2,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	insertionsort(arr,n);
	display(arr,n);
	
	return 0;
}
