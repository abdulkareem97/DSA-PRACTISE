#include <iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    // code here
    for(int i=1;i<arr.size();i++){
        int ele = arr[i];
        int j = i-1;
        while(j>-1 && ele<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = ele;
    }
}

int main() {
    
    return 0;
}
