// Subarray with 0 sum
// Difficulty: MediumAccuracy: 39.79%Submissions: 287K+Points: 4Average Time: 20m
// Given an array of integers, arr[]. Find if there is a subarray (of size at least one) with 0 sum. Return true/false depending upon whether there is a subarray present with 0-sum or not.

// Examples:

// Input: arr[] = [4, 2, -3, 1, 6]
// Output: true
// Explanation: 2, -3, 1 is the subarray with a sum of 0.
// Input: arr = [4, 2, 0, 1, 6]
// Output: true
// Explanation: 0 is one of the element in the array so there exist a subarray with sum 0.
// Input: arr = [1, 2, -1]
// Output: false

#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;

bool subArrayExists(vector<int> &arr)
{
    // Your code here
    unordered_set<int> s;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0 || s.find(sum) != s.end())
        {
            return true;
        }
        s.insert(sum);
    }
    return false;
}

int main()
{

    return 0;
}
