#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 215. Kth Largest Element in an Array

int kthSmallest(vector<int> &arr, int k)
{
    // code here
    int m = INT_MIN;
    for (auto i : arr)
    {
        if (m < i)
            m = i;
    }
    vector<bool> v(m + 1, false);
    for (auto i : arr)
    {
        v[i] = true;
    }
    int c = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i])
            c++;
        if (k == c)
            return i;
    }
    return -1;
}

int pivot(vector<int> &nums, int l, int r)
{
    int pivot = nums[l]; // Choose first element as pivot
    int i = l + 1, j = r;

    while (i <= j)
    {
        while (i <= j && nums[i] < pivot)
            i++;
        while (i <= j && nums[j] > pivot)
            j--;

        if (i <= j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

    swap(nums[l], nums[j]); // Place pivot in correct position
    return j;               // Pivot index
}

int findKthLargest(vector<int> &nums, int k)
{
    int l = 0, r = nums.size() - 1;
    int target = nums.size() - k; // Convert kth largest to index

    while (l <= r)
    {
        int j = pivot(nums, l, r);

        if (j == target)
            return nums[j]; // Found kth largest
        else if (j < target)
            l = j + 1; // Search in right partition
        else
            r = j - 1; // Search in left partition
    }

    return -1; // Should never reach here
}

int main()
{
    vector<int> v = {100, 200, 900, 300, 400, 500};
    v = {7 ,10 ,4 ,20, 15};
    cout << " Kth smallesst element is " << kthSmallest(v, 3)<<endl;
    cout << " Kth largest element is " << kthSmallest(v, 2);

    return 0;
}
