// insertion sort

#include <iostream>
#include<algorithm>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}

void insertionSort(int arr[],int size){
    for(int i=0;i<size;i++){
        // int k=i;
        int ele = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>ele){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=ele;
    // printArray(arr,size);
    }
}





int main() {
    int arr[] = {4,5,3,2,1};
    int size = sizeof(arr)/sizeof(int);
    insertionSort(arr,size);
    printArray(arr,size);
    
    
    return 0;
}
