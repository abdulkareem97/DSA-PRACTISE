// 74. Search a 2D Matrix
// Solved
// Medium
// Topics
// Companies
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

 

// Example 1:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

#include <iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int s=0,e=(m*n-1);
    while(s<=e){
        // s=1,e=1;
        int mid = (s+e)/2;
        // cout<<mid<<" "<< (mid/n) << (mid%n);
        // break;
        if(matrix[mid/n][mid%n]==target){
            return true;
        }else if(matrix[mid/n][mid%n]<target){
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    return false;
}


int main() {
    
    return 0;
}
