// Reverse an Array


#include <iostream>
#include<vector>
using namespace std;


void reverseArray(vector<int> &arr,int i=0) {
    // code here
    if(i+1>arr.size()/2) return;
    int last = arr.size() -1 - i;
    swap(arr[i],arr[last]);
    reverseArray(arr,i+1);
    
}

int main() {
    
    return 0;
}
