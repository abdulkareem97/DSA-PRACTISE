// Introduction to array

#include <iostream>
#include <array>
#include "p1.h"
#include "p1.h"

using namespace std;

template <typename T, unsigned int n>
int ls(const array<T, n> &arr, int ele)
{
    // Use the array's size function to determine the size
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            return i; // Return index if element is found
        }
    }
    return -1; // Return -1 if element is not found
}

int maxElemet(int arr[], int n)
{
    int max = -2147483647 - 1;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

int sumElemet(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

void reverserArray(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - i - 1]);
    }
}

void swapAlternate(int *arr, int size)
{
    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
            swap(arr[i], arr[i + 1]);
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// We can initialize the array with any value by using the fill_n command

// Example code:

// #include<iostream>
// using namespace std;

// int main() {
//     int array[100];

//     //To initialize the array with value'1'.
//     fill_n(array, 100, 1);

//     //To check the array input (kewaal 5 hi kari h print)
//     for(int i = 0; i <= 5; i++){
//         cout << array[i] << endl;
//     }

// }

int main()
{
    array<int, 5> arr = {10, 20, 30, 40, 50};

    int element = 30;
    int index = ls(arr, element); // Call the function to find the index of the element

    // if (index != -1) {
    //     cout << "Element " << element << " found at index: " << index << endl;
    // } else {
    //     cout << "Element " << element << " not found!" << endl;
    // }

    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[7] = {7, 5, 2, 56, 9, 1, 0};

    int arr3[4] = {1, 2, 3, 4};

    // reverserArray(arr1,5);

    // for(int i=0;i<5;i++){
    //     cout<<arr1[i]<<" ";
    // }

    // cout<<sizeof(arr1)/sizeof(int);

    // cout<<maxElemet(arr2,7);
    // cout<<sumElemet(arr1,5);
    swapAlternate(arr1, 5);
    // printArray(arr1,5);
    swapAlternate(arr3, 4);
    printArray(arr3, 4);

    int arr5[100];
    fill_n(arr5, 3, 1);

    for (int i = 0; i < 6; i++)
    {
        cout << " " << arr5[i];
    }

    return 0;
}
