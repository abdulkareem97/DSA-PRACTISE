// Median in a row-wise sorted Matrix
// Difficulty: HardAccuracy: 55.05%Submissions: 132K+Points: 8
// Given a row-wise sorted matrix where the number of rows and columns is always odd, find the median of the matrix.

// Examples:

// Input: mat = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
// Input: mat = [[1], [2], [3]]
// Output: 2
// Explanation: Sorting matrix elements gives us {1,2,3}. Hence, 2 is median
// Input: mat = [[3], [5], [8]]
// Output: 5
// Explanation: Sorting matrix elements gives us {3,5,8}. Hence, 5 is median.


#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int median(vector<vector<int>> &mat) {
    // code here
    int mi = INT_MAX,ma=INT_MIN;
    int c = mat[0].size();
    for(int i=0;i<mat.size();i++){
        mi = min(mi,mat[i][0]);
        ma = max(ma,mat[i][c-1]);
    }
    
    int lo = mi,hi=ma;
    int res = (mat.size()*mat[0].size()+1)/2;
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        int place = 0;
        for(int i=0;i<mat.size();i++){
            place += upper_bound(mat[i].begin(),mat[i].end(),mid) - mat[i].begin();
        }
        if(place<res){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }
    return lo;
}

int main() {
    
    return 0;
}
