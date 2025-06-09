#include <iostream>
using namespace std;

void selectionsort(int arr[],int n){
	for(int i=0;i<n;i++){
		int smallindex=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[smallindex]){
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
	int arr[]={29, 10, 14, 37, 13};
	int n=sizeof(arr)/sizeof(arr[0]);
	selectionsort(arr,n);
	
	cout<<"Sorted Array: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	return 0;
}


