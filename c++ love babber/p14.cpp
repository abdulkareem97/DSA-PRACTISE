// Binary Search Interview Questions

#include <iostream>
using namespace std;

int pivotElement(int arr[], int size)
{
    int left{0}, right{size - 1};
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] > arr[size - 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

int bs(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int squareRoot(int num)
{
    int left = 1, right = num - 1, ans = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (mid * mid <= num)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

float addPrecision(int num, int ans, int k)
{

    float val = ans,x=1;
    
    for (int j = 1; j <= k; j++)
    {
        // cout<<"here";
        x = x/10;
        for (float i = val; i*i < num; i += x)
        {
           
           val = i;
            // cout<<"here2"<<;
        }
    }
    return val;
}

int main()
{
    int arr[] = {11, 13, 15, 17};
    int s = sizeof(arr) / sizeof(int);
    int key = 1;
    cout << " Pivot Element in rotated array is " << arr[pivotElement(arr, s)] << endl;
    int left{}, right{}, pivot{pivotElement(arr, s)};
    if (key > arr[0])
    {
        left = 0;
        right = pivot - 1;
    }
    else
    {
        left = pivot;
        right = s - 1;
    }
    cout << " Element Found At index " << bs(arr, left, right, key) << endl;

    int sq = 12;
    int sq1 = squareRoot(sq);
    cout << " Square Root Of element is " << sq1 << endl;
    cout << " Square Root Of element With Presiision  is " << addPrecision(sq, sq1, 6) << endl;

    return 0;
}
