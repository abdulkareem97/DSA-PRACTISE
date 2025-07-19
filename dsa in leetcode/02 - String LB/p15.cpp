// Next Permutation


#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


void nextPermutation(vector<int>& arr) {
    // code here
    int pivot = -1;
    for(int i=arr.size()-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            pivot = i;
            break;
        }
    }
    if(pivot==-1){
        reverse(arr.begin(),arr.end());
        return ;
    }
    int g = pivot+1;
    for(int i=arr.size()-1;i>pivot;i--){
        if(arr[i]>arr[pivot]){
            g = i;
            break;
        }
    }
    swap(arr[g],arr[pivot]);
    reverse(arr.begin()+pivot+1,arr.end());
    // return arr;
    
    
}

int main() {
    
    return 0;
}
