// Second Largest


#include <iostream>
#include<vector>
using namespace std;


int getSecondLargest(vector<int> &arr) {
    // Code Here
    int fmax = arr[0];
    int smax = -1;
    
    for(int i=1;i<arr.size();i++){
        if(fmax<arr[i]){
            smax = fmax;
            fmax = arr[i];
        }else if(fmax!=arr[i] && smax<arr[i]){
            smax = arr[i];
        }
    }
    return smax;
}


int main() {
    
    return 0;
}
