#include <iostream>
#include<vector>
using namespace std;



// Function that takes last element as pivot, places the pivot element at
// its correct position in sorted array, and places all smaller elements
// to left of pivot and all greater elements to right of pivot.
int partition(vector<int>& arr, int low, int high) {
    // code here
    int pivot = low;
    int s = low+1;
    int e = high;
    while(s<=e){
        while(s<=e && arr[s]<arr[pivot]) s++;
        while(s<=e && arr[e]>arr[pivot]) e--;
        // cout<<s<<" "<<e<<endl;
        if(s<=e)
        swap(arr[s++],arr[e--]);
    }
    swap(arr[e],arr[pivot]);
    return e;
}


void quickSort(vector<int>& arr, int low, int high) {
    // code here
    if(low<high){
        int pivot = partition(arr,low,high);
        // cout<<pivot<<" "<<arr[pivot]<<endl;
        // printArray(arr);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}

int main() {
    
    return 0;
}
