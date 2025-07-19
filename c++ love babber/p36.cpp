// Quick Sort 

#include <iostream>
#include <vector>
using namespace std;

int partiton(vector<int> &arr,int s,int e){
    int p = s;
    int pivot = arr[p];
    s++;
    while(s<=e){
        while(s<=e && pivot>arr[s]) s++;
        while(s<=e && pivot<arr[e]) e--;
        if(s<=e){
            swap(arr[s],arr[e]);
            s++;e--;
        }

    }
    swap(arr[p],arr[e]);
    return e;
}

//  Lomuto Partition 
int partitonLomuto(vector<int> &arr,int s,int e){
    int pivot = e;
    // sending small to back and pointing s to element larger than pivot
    for(int j=s;j<e;j++){
        if(arr[j]<arr[pivot]){
            swap(arr[j],arr[s]);
            s++;
        }
    }
    swap(arr[s],arr[pivot]);
    return s;
}



void qs(vector<int> &arr,int s,int e){
    if(s>e) return;
    int p = partitonLomuto(arr,s,e);
    // cout<< " " <<p <<endl;
    qs(arr,p+1,e);
    qs(arr,s,p-1);
}

int main() {

    vector<int> v{9,8,7,3,4,5};

    v = {9,0,3,2};
    v = {7,10,4,20,15};
    qs(v,0,v.size()-1);
    for(auto i:v){
        cout<<" "<<i;
    }
    
    return 0;
}
