// Kadane's Algorithm

// Given an integer array arr[]. You need to find the maximum sum of a subarray.

// Examples:

// Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
// Output: 11
// Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.
// Input: arr[] = [-2, -4]
// Output: -2
// Explanation: The subarray {-2} has the largest sum -2.
// Input: arr[] = [5, 4, 1, 7, 8]
// Output: 25
// Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.

#include <iostream>
#include<vector>
using namespace std;

int maxSubarraySum(vector<int> &arr)
{
    // Your code here
    int maxSum = arr[0];
    int ans = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        maxSum = max(arr[i], maxSum + arr[i]);
        ans = max(ans, maxSum);
    }
    return ans;
}

int main()
{

    return 0;
}
