#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

void bubblesort(int arr[], int n) {
    bool swapped = false;
    for(int i = 0; i < n; i++) {
        swapped = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        if(minIndex != i)
            swap(arr[i], arr[minIndex]);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void mergesort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main() {
    srand(time(0));
    const int size = 10000;
    int original[size], arr1[size], arr2[size], arr3[size];

    for(int i = 0; i < size; i++) {
        original[i] = rand() % 2000;
    }

    copy(original, original + size, arr1);
    copy(original, original + size, arr2);
    copy(original, original + size, arr3);

    auto start1 = high_resolution_clock::now();
    bubblesort(arr1, size);
    display(arr1,size);
    cout<<endl;
    cout<<"End of Bubble Sort: "<<endl;
    cout<<endl;
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1);

    auto start2 = high_resolution_clock::now();
    mergesort(arr2, 0, size - 1);
    display(arr2,size);
    cout<<endl;
    cout<<"End of Merge Sort: "<<endl;
    cout<<endl;
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2 - start2);

    auto start3 = high_resolution_clock::now();
    selectionSort(arr3, size);
    display(arr3,size);
    cout<<endl;
    cout<<"End of Selection Sort"<<endl;
    cout<<endl;
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<milliseconds>(end3 - start3);
    
    cout<<endl;
    cout << "Bubble Sort Execution: " << duration1.count() << " ms\n";
    cout << "Merge Sort Execution: " << duration2.count() << " ms\n";
    cout << "Selection Sort Execution: " << duration3.count() << " ms\n";

    return 0;
}

