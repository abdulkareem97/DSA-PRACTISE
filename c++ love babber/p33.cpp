// Recursion and binary search

#include <iostream>
#include <vector>
using namespace std;



int bs(vector<int> &v,int left,int right,int ele){

    if(left<=right){
        int mid = (left+right)/2;
        // cout << " mid value is "<<mid<<endl;
        if(v[mid]==ele) return mid;
        else if(v[mid]<ele) return bs(v,mid+1,right,ele);
        else return bs(v,left,mid-1,ele);
    }
    return -1;
}

int main() {
    vector<int> v = {10,20,30,40,50};
    cout << "Element is at "<<bs(v,0,v.size()-1,30);
    return 0;
}
