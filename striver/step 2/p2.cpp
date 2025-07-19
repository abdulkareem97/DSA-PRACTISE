#include <iostream>
#include<vector>
using namespace std;

// Function to sort the array using bubble sort algorithm.
void bubbleSort(vector<int>& arr) {
    // Your code here
    for(int i=0;i<arr.size();i++){
        bool swapped = false;
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){
                swapped = true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(!swapped) break;
    }
}

int main() {
    
    return 0;
}
