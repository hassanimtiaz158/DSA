#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int binarysearchiterative(int arr[],int n,int target){
	int low=0;
	int high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==target){
			return mid;
		}else if(arr[mid]<target){
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	return -1;
}

int binarysearchrecursive(int arr[],int low,int high,int target){
	if(low>high){
		return -1;
	}
	int mid=low+(high-low)/2;
	if(arr[mid]==target){
		return mid;
	}else if(arr[mid]<target){
		return binarysearchrecursive(arr,mid+1,high,target);
	}else{
		return binarysearchrecursive(arr,low,mid-1,target);
	}
}

int main(){
	const int size=20000;
	int arr[size];
	for(int i=0;i<size;++i){
		arr[i]=i+1;
	}
	int low=0;
	int high=size-1;
	int target=19999;
	
	auto start1=high_resolution_clock::now();
	cout<<"Iterative: "<<binarysearchiterative(arr,size,target)<<" index"<<endl;
	auto end1=high_resolution_clock::now();
	
	auto start2=high_resolution_clock::now();
	cout<<"Recursive: "<<binarysearchrecursive(arr,low,high,target)<<" index"<<endl;
	auto end2=high_resolution_clock::now();
	cout<<endl;
	auto time1=duration_cast<nanoseconds>(end1-start1).count();
	auto time2=duration_cast<nanoseconds>(end2-start2).count();
	
	cout<<"Iterative approach: "<<time1<<" ns"<<endl;
	cout<<"Recursive approach: "<<time2<<" ns"<<endl;
	
	return 0;
}
