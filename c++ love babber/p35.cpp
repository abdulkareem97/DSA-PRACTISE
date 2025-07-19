// Merge Sort

#include <iostream>
#include<vector>
using namespace std;

void merger(vector<int> &arr,int s,int m,int e){
    vector<int> v;
    int j = m+1, k =s;
    while(s<=m && j<=e){
        if(arr[s]<arr[j]) v.push_back(arr[s++]);
        else v.push_back(arr[j++]);
    }
    while(s<=m){
         v.push_back(arr[s++]);
    }
    while(s<=m){
         v.push_back(arr[j++]);
    }
    for(int i=0;i<v.size();i++){
        arr[k++] = v[i];
    }
}

void mergesortRecursionCall(vector < int > & arr, int s,int l){
    if(s>=l){
        return;
    }
    int mid = (s+l)/2;
    mergesortRecursionCall(arr,mid+1,l);
    mergesortRecursionCall(arr,s,mid);
    merger(arr,s,mid,l);
}



void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    mergesortRecursionCall(arr,0,arr.size()-1);
}

int main() {
    vector<int> v = {10,90,50,60,20};
    mergeSort(v,v.size()-1);
    for(auto i:v){
        cout<< " "<< i;
    }
    
    return 0;
}
// 🔬⚕️💻 Science, Medicine, and Tech Fusion
// The Smart Trio