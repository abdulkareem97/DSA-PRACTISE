// Smallest subarray with sum greater than x
// Difficulty: EasyAccuracy: 37.07%Submissions: 135K+Points: 2Average Time: 20m
// Given a number x and an array of integers arr, find the smallest subarray with sum greater than the given value. If such a subarray do not exist return 0 in that case.

// Examples:

// Input: x = 51, arr[] = [1, 4, 45, 6, 0, 19]
// Output: 3
// Explanation: Minimum length subarray is [4, 45, 6]
// Input: x = 100, arr[] = [1, 10, 5, 2, 7]
// Output: 0
// Explanation: No subarray exist
// Constraints:
// 1 ≤ arr.size, x ≤ 105
// 0 ≤ arr[] ≤ 104

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int smallestSubWithSum(int x, vector<int>& arr) {
    // Your code goes here
    int ans = INT_MAX,j=0,i=0,n=arr.size(),sum=0;
    while(j<n){
        
        while(j<n && sum <= x){
            sum+=arr[j++];
        }
        if(j==n && sum <= x) break;
        // cout<<sum<<" "<<sum-arr[i]<<endl;
        while(i<j && sum-arr[i] > x){
            sum-=arr[i++];
        }
        // cout<<" "<<i<<" "<<j<<endl;
        ans = min(ans,j-i);
        sum-=arr[i++];
        
    }
    if(ans==INT_MAX) return 0;
    
    return ans;
    
}

int main() {
    
    return 0;
}
