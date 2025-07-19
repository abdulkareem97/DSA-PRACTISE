
// Selection sort

#include <iostream>
#include<algorithm>
using namespace std;

void selectionSort(int arr[],int size){
    for(int i=0;i<size;i++){
        int k=i;
        for(int j=i;j<size;j++){
            if(arr[j]<arr[k]){
                k=j;
            }
        }
        swap(arr[i],arr[k]);
    }
}


void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}


int main() {
    int arr[] = {4,5,3,2,1};
    int size = sizeof(arr)/sizeof(int);
    selectionSort(arr,size);
    printArray(arr,size);
    
    return 0;
}
