// Maximum Product Subarray
// Difficulty: MediumAccuracy: 18.09%Submissions: 428K+Points: 4
// Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr[].

// Note: It is guaranteed that the output fits in a 32-bit integer.

// Examples

// Input: arr[] = [-2, 6, -3, -10, 0, 2]
// Output: 180
// Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.
// Input: arr[] = [-1, -3, -10, 0, 6]
// Output: 30
// Explanation: The subarray with maximum product is {-3, -10} with product = (-3) * (-10) = 30.
// Input: arr[] = [2, 3, 4]
// Output: 24
// Explanation: For an array with all positive elements, the result is product of all elements.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int> &arr)
{
    // Your Code Here
    int curMax = arr[0];
    int curMin = arr[0];
    int maxProd = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        int temp = max({arr[i], arr[i] * curMax, arr[i] * curMin});
        curMin = min({arr[i], arr[i] * curMax, arr[i] * curMin});
        curMax = temp;
        maxProd = max({maxProd, curMin, curMax});
    }
    return maxProd;
}

int main()
{
    vector<int> v = {1,2,-1,-3,-10};
    cout << maxProduct(v);

    return 0;
}
