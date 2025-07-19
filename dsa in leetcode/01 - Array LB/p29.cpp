// Triplet Sum in Array
// Difficulty: MediumAccuracy: 35.0%Submissions: 316K+Points: 4Average Time: 15m
// Given an array arr[] and an integer target, determine if there exists a triplet in the array whose sum equals the given target.

// Return true if such a triplet exists, otherwise, return false.

// Examples

// Input: arr[] = [1, 4, 45, 6, 10, 8], target = 13 
// Output: true 
// Explanation: The triplet {1, 4, 8} sums up to 13
// Input: arr[] = [1, 2, 4, 3, 6, 7], target = 10 
// Output: true 
// Explanation: The triplets {1, 3, 6} and {1, 2, 7} both sum to 10. 
// Input: arr[] = [40, 20, 10, 3, 6, 7], target = 24 
// Output: false 
// Explanation: No triplet in the array sums to 24
// Constraints:
// 3 ≤ arr.size() ≤ 103
// 1 ≤ arr[i] ≤ 105

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool hasTripletSum(vector<int> &arr, int target) {
    // Your Code Here
    sort(arr.begin(),arr.end());
    int n = arr.size();
    for(int i=0;i<n;i++){
        int remain = target - arr[i];
        int l=i+1,r=n-1;
        while(l<r){
            if(remain - arr[l] -arr[r]==0) return true;
            else if(remain - arr[l] - arr[r] < 0 ) r--;
            else l++;
        }
    }
    return false;
}

int main() {
    
    return 0;
}
