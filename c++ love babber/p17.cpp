// Bubble sort

#include <iostream>
#include<algorithm>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}

void bubbleSort(int arr[],int size){
    for(int i=0;i<size;i++){
        // int k=i;
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                    swap(arr[j+1],arr[j]);
            
            }
        }
    // printArray(arr,size);
    }
}





int main() {
    int arr[] = {4,5,3,2,1};
    int size = sizeof(arr)/sizeof(int);
    bubbleSort(arr,size);
    printArray(arr,size);
    
    
    return 0;
}
