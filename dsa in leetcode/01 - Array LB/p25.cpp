// Longest Consecutive Subsequence
// Difficulty: MediumAccuracy: 33.0%Submissions: 344K+Points: 4Average Time: 25m
// Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

// Examples:

// Input: arr[] = [2, 6, 1, 9, 4, 5, 3]
// Output: 6
// Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.
// Input: arr[] = [1, 9, 3, 10, 4, 20, 2]
// Output: 4
// Explanation: 1, 2, 3, 4 is the longest consecutive subsequence.
// Input: arr[] = [15, 13, 12, 14, 11, 10, 9]
// Output: 7
// Explanation: The longest consecutive subsequence is 9, 10, 11, 12, 13, 14, 15, which has a length of 7.

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutive(vector<int> &arr)
{
    unordered_set<int> st;
    int res = 0;

    // Hash all the array elements
    for (int val : arr)
        st.insert(val);

    // check each possible sequence from the start then update optimal length
    for (int val : arr)
    {

        // if current element is the starting element of a sequence
        if (st.find(val) != st.end() && st.find(val - 1) == st.end())
        {

            // Then check for next elements in the sequence
            int cur = val, cnt = 0;
            while (st.find(cur) != st.end())
            {

                // Remove this number to avoid recomputation
                st.erase(cur);
                cur++;
                cnt++;
            }

            // update  optimal length
            res = max(res, cnt);
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {2, 6, 1, 9, 4, 5, 3};
    cout << longestConsecutive(arr);
    return 0;
}