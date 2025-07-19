// problems on binary search

// not solved in leetcode i will solve once completed stl library
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int firstOccurance(int arr[], int size, int key)
{
    int left = 0, right = size - 1, index = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
        {

            index = mid;
            // return mid;
            right = mid - 1;
        }
        else if (arr[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return index;
}
int lastOccurance(int arr[], int size, int key)
{
    int left = 0, right = size - 1, index = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        // cout<<" mid value "<<mid<<" elemet "<<arr[mid]<<endl;
        if (arr[mid] == key)
        {

            index = mid;
            left = mid + 1;
        }
        else if (arr[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
        // cout<<mid<<" "<<left<<" "<<right<<endl;
        // cout<<left<<endl;
    }
    // cout<<left<<right<<endl;
    return index;
}

//
int peekIndexMountain(int arr[], int size)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            // cout<<arr[left]<<arr[mid]<<arr[ri]
            return mid;
        }
        else if (arr[mid] > arr[mid - 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

//  First and Last Position of an Element In Sorted Array - coding ninja

int firstOccurance(vector<int> &arr, int n, int k)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
        {
            e = mid - 1;
        }
        else if (arr[mid] < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return s;
}
int lastOccurance(vector<int> &arr, int n, int k)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
        {
            s = mid + 1;
        }
        else if (arr[mid] < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return e;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    // Write your code here
    pair<int, int> p = {firstOccurance(arr, n, k), lastOccurance(arr, n, k)};

    if (arr[p.first] != k)
    {
        p = {-1, -1};
    }
    // pair<int,int> p = {1,1};
    // p.first = firstOccurance(arr,n,k);
    return p;
}

// 852. Peak Index in a Mountain Array
int peakIndexInMountainArray(vector<int> &arr)
{

    int s = 0, e = arr.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (mid > 0 && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (mid <= 0 || arr[mid] > arr[mid - 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return 0;
}

// 724. Find Pivot Index
// Given an array of integers nums, calculate the pivot index of this array.

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

// Return the leftmost pivot index. If no such index exists, return -1.

// Example 1:

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11

int pivotIndex(vector<int> &nums)
{
    int rightSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        rightSum += nums[i];
    }

    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        rightSum -= nums[i];
        if (leftSum == rightSum)
        {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}

int main()
{

    int arr[] = {1, 1, 1, 1, 1, 2, 3, 4, 4};
    int size = sizeof(arr) / sizeof(int);
    // int s = size(arr);

    int ele = 4;

    // cout<<"ELement First Occurance Found At Index "<<firstOccurance(arr,size,ele)<<endl;
    // cout<<"ELement Last Occurance Found At Index "<<lastOccurance(arr,size,ele)<<endl;

    int arr1[] = {3, 4, 5, 1};
    int size1 = sizeof(arr1) / sizeof(int);

    cout << " Mountain Element is " << arr1[peekIndexMountain(arr1, size1)] << endl;

    return 0;
}
