#include <iostream>
using namespace std;

int dividearray(int arr[],int low,int high){
	int pivot=arr[high];
	int i=low-1;
	for(int j=low;j<high;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[high]);
	return i+1;
}

void quicksort(int arr[],int low,int high){
	if(low<high){
		int p=dividearray(arr,low,high);
	quicksort(arr,low,p-1);
	quicksort(arr,p+1,high);
    }
}

void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[]={2,7,0,7,3,2,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	quicksort(arr,0,n-1);
	print(arr,n);
	
	return 0;
}
