// More than n/k Occurrences
// Difficulty: EasyAccuracy: 58.35%Submissions: 118K+Points: 2Average Time: 45m
// Given an array arr and an element k. The task is to find the count of elements in the array that appear more than n/k times and n is length of arr.

// Examples :

// Input: arr = [3, 1, 2, 2, 1, 2, 3, 3], k = 4
// Output: 2
// Explanation: In the given array, 3 and 2 are the only elements that appears more than n/k times.
// Input: arr = [2, 3, 3, 2], k = 3
// Output: 2
// Explanation: In the given array, 3 and 2 are the only elements that appears more than n/k times. So the count of elements are 2.
// Input: arr = [1, 4, 7, 7], k = 2
// Output: 0
// Explanation: In the given array, no element appears more than n/k times.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countOccurence(vector<int> &arr, int k)
{
    // Your code here
    unordered_map<int, int> m;
    for (int i = 0; i < arr.size(); i++)
    {
        m[arr[i]]++;
    }
    int c = 0, a = arr.size() / k;
    for (auto i : m)
    {
        if (i.second > a)
            c++;
    }
    return c;
}

int main()
{

    return 0;
}
