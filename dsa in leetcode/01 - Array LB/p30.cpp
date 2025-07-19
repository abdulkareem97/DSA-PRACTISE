// Trapping Rain Water
// Difficulty: HardAccuracy: 33.14%Submissions: 464K+Points: 8Average Time: 20m
// Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

// Examples:

// Input: arr[] = [3, 0, 1, 0, 4, 0 2]
// Output: 10
// Explanation: Total water trapped = 0 + 3 + 2 + 3 + 0 + 2 + 0 = 10 units.

// Input: arr[] = [3, 0, 2, 0, 4]
// Output: 7
// Explanation: Total water trapped = 0 + 3 + 1 + 3 + 0 = 7 units.
// Input: arr[] = [1, 2, 3, 4]
// Output: 0
// Explanation: We cannot trap water as there is no height bound on both sides.
// Input: arr[] = [2, 1, 5, 3, 1, 0, 4]
// Output: 9
// Explanation: Total water trapped = 0 + 1 + 0 + 1 + 3 + 4 + 0 = 9 units.


#include <iostream>
#include<vector>
using namespace std;

int maxWater(vector<int> &arr) {
    // code here
    int water = 0;
    int l=1,r = arr.size()-2;
    int lmax = arr[0],rmax=arr[arr.size()-1];
    
    while(l<=r){
        if(lmax >= rmax){
            water += max(0,rmax-arr[r]);
            rmax = max(rmax,arr[r]);
            r--;
        }else{
            water+=max(0,lmax-arr[l]);
            lmax = max(lmax,arr[l]);
            l++;
        }
    }
    return water;
}

int main() {
    
    return 0;
}
