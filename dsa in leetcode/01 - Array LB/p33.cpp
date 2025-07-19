// Three way partitioning
// Difficulty: EasyAccuracy: 41.58%Submissions: 175K+Points: 2Average Time: 20m
// Given an array and a range a, b. The task is to partition the array around the range such that the array is divided into three parts.
// 1) All elements smaller than a come first.
// 2) All elements in range a to b come next.
// 3) All elements greater than b appear in the end.
// The individual elements of three sets can appear in any order. You are required to return the modified array.

// Note: The generated output is true if you modify the given array successfully. Otherwise false.

// Geeky Challenge: Solve this problem in O(n) time complexity.

// Examples:

// Input: arr[] = [1, 2, 3, 3, 4], a = 1, b = 2
// Output: true
// Explanation: One possible arrangement is: {1, 2, 3, 3, 4}. If you return a valid arrangement, output will be true.
// Input: arr[] = [1, 4, 3, 6, 2, 1], a = 1, b = 3
// Output: true
// Explanation: One possible arrangement is: {1, 3, 2, 1, 4, 6}. If you return a valid arrangement, output will be true.
// Constraints:
// 1 <= arr.size()<= 106
// 1 <= array[i], a, b <= 109

// Dutch National Flag Algorithm

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int>& arr, int a, int b) {
    // code here
    int l=0,m=0,h=arr.size()-1;
    
    while(m<=h){
        if(arr[m]<a){
            swap(arr[l++],arr[m++]);
        }else if(arr[m]>=a && arr[m]<b){
            m++;
        }else{
            swap(arr[h--],arr[m]);
        }
    }
}

int main() {
    
    return 0;
}
