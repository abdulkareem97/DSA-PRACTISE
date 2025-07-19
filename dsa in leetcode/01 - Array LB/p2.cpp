// Find the maximum and minimum element in an array

#include <iostream>
#include<vector>
#include <climits>
using namespace std;

int max(vector<int> &v){
    int m = INT_MIN;
    for(auto i:v){
        if(m<i) m=i;
    }
    return m;
}

int min(vector<int> &v){
    int m = INT_MAX;
    for(auto i:v){
        if(m>i) m=i;
    }
    return m;
}

int main() {
    vector<int> v = {10,90,40,50,1,9,10,3};

    cout<<"Max value "<<max(v)<<" min value "<<min(v);
    
    return 0;
}
