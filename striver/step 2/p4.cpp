#include <iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int l,int mid, int end){
    vector<int> temp;
    int s = l;
    int r = mid+1;
    while(s<=mid && r<=end){
        if(arr[s]<arr[r]){
            temp.push_back(arr[s++]);
        }else{
            temp.push_back(arr[r++]);
        }
    }
    while(s<=mid){
        temp.push_back(arr[s++]);
    }
    while(r<=end) temp.push_back(arr[r++]);
    for(auto i:temp){
        arr[l++] = i;
    }
}
  void mergeSort(vector<int>& arr, int l, int r) {
      // code here
      if(l<r){
          int mid = (l+r)/2;
          // cout<<l<<" "<<r;
          mergeSort(arr,l,mid);
          mergeSort(arr,mid+1,r);
          merge(arr,l,mid,r);
      }
  }

int main() {
    
    return 0;
}
