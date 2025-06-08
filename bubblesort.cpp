#include <iostream>
using namespace std;

void bubblesort(int arr[],int size){
	int swaps=0;
	for(int i=0;i<size-1;i++){
		bool swapped=false;
		for(int j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swaps++;
				swapped=true;
			}
		}
		if(!swapped){
			break;
		}
	}
	cout<<"Sorted array: ";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Swaps: "<<swaps<<endl;
}

int main(){
	int size;
	cout<<"Size: ";
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++){
		cout<<"Enter element "<<i<<": ";
		cin>>arr[i];
	}
	bubblesort(arr,size);
	
	return 0;
}
