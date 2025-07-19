// Largest Element in Array


#include <iostream>
#include<vector>
using namespace std;


int largest(vector<int> &arr) {
    // code here
    int m = arr[0];
    for(int i=0;i<arr.size();i++){
        if(m<arr[i]) m = arr[i];
    }
    return m;
}

int main() {
    
    return 0;
}
