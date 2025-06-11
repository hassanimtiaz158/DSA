#include <iostream>
#include <vector>
using namespace std;

void mergesort(vector<int>& arr,int start,int mid,int end){
	int i=start;
	int j=mid+1;
	vector<int> temp;
	while(i<=mid && j<=end){
		if(arr[i]<=arr[j]){
			temp.push_back(arr[i]);
			i++;
		}else{
			temp.push_back(arr[j]);
			j++;
		}
	}
	while(i<=mid){
		temp.push_back(arr[i]);
		i++;
	}
	while(j<=end){
		temp.push_back(arr[j]);
		j++;
	}
	for(int k=0;k<temp.size();k++){
		arr[start+k]=temp[k];
	}
}

void merge(vector<int>& arr,int start,int end){
	if(start>=end){
		return;
	}
	int mid=start+(end-start)/2;
	merge(arr,start,mid);
	merge(arr,mid+1,end);
	mergesort(arr,start,mid,end);
}



int main(){
	vector<int> arr={2,5,3,7,9,6,4,10};
	cout<<"Original Array: ";
	for(int num:arr){
		cout<<num<<" ";
	}
	merge(arr,0,arr.size()-1);
	cout<<endl;
	cout<<"Sorted Array: ";
	for(int num:arr){
		cout<<num<<" ";
	}
	
	return 0;
}
