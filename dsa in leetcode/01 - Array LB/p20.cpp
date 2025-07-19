// Common in 3 Sorted Arrays
// Difficulty: EasyAccuracy: 22.16%Submissions: 411K+Points: 2
// You are given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// If there are no such elements return an empty array. In this case, the output will be -1.

// Note: can you handle the duplicates without using any additional Data Structure?

// Examples :

// Input: arr1 = [1, 5, 10, 20, 40, 80] , arr2 = [6, 7, 20, 80, 100] , arr3 = [3, 4, 15, 20, 30, 70, 80, 120]
// Output: [20, 80]
// Explanation: 20 and 80 are the only common elements in arr, brr and crr.
// Input: arr1 = [1, 2, 3, 4, 5] , arr2 = [6, 7] , arr3 = [8,9,10]
// Output: [-1]
// Explanation: There are no common elements in arr, brr and crr.
// Input: arr1 = [1, 1, 1, 2, 2, 2], B = [1, 1, 2, 2, 2], arr3 = [1, 1, 1, 1, 2, 2, 2, 2]
// Output: [1, 2]
// Explanation: We do not need to consider duplicates
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Here n = Total sizes of arr1, arr2, and arr3

#include <iostream>
#include <vector>
using namespace std;

vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                           vector<int> &arr3)
{
    // Code Here
    // int maxSize = min(arr1.size(),min(arr2.size(),arr3.size()));
    int i = 0, j = 0, k = 0;
    vector<int> v;
    while (i < arr1.size() && j < arr2.size() && k < arr3.size())
    {
        // cout<<" "<<arr1[i]<<" "<<arr2[j]<<" "<<arr3[k]<<endl;
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
        {
            if (v.empty() || v.back() != arr1[i])
            {

                v.push_back(arr1[i]);
            }
            i++;
            j++;
            k++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr2[j] < arr3[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    return v;
}

int main()
{

    return 0;
}
