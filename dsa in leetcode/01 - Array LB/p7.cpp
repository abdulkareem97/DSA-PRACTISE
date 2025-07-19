// Rotate Array by One - gfg
// Given an array arr, rotate the array by one position in clockwise direction.

// Examples:

// Input: arr[] = [1, 2, 3, 4, 5]
// Output: [5, 1, 2, 3, 4]
// Explanation: If we rotate arr by one position in clockwise 5 come to the front and remaining those are shifted to the end.
// Input: arr[] = [9, 8, 7, 6, 4, 2, 1, 3]
// Output: [3, 9, 8, 7, 6, 4, 2, 1]
// Explanation: After rotating clock-wise 3 comes in first position.

#include <iostream>
#include<vector>
using namespace std;
 void rotate(vector<int> &arr) {
        // code here
        int ele = arr[arr.size()-1];
        for(int i=arr.size()-1;i>0;i--){
            arr[i] = arr[i-1];
        }
        arr[0] = ele;
    }

int main() {
    
    return 0;
}

