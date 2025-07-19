// Leetcode problem

#include <iostream>
#include <algorithm>
using namespace std;

void swapAlternate(int arr[], int size)
{
    for (int i = 1; i < size; i += 2)
    {
        swap(arr[i - 1], arr[i]);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findUnique(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= arr[i];
    }
    return ans;
}

bool uniqueOccurace(int arr[], int n)
{
    int x[2000] = {};
    for (int i = 0; i < n; i++)
    {
        x[arr[i]]++;
    }
    sort(x, x + 2000);
    for (int i = 0; i < 2000; i++)
    {
        if (x[i] && x[i] == x[i - 1])
        {
            return false;
        }
    }
    return true;
}

int findDublicate(int arr[], int n)
{
    // 1 1 2 3 n 4
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        maxSum += i;
    }
    return sum - maxSum;
    // 1 1 2 3 = 7
    //  1  2 3   1 1 2 3 = 14
}

int *findAllDublicate(int arr[], int n)
{
    int x[100] = {};
    int ans[10] = {};
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[arr[i]])
        {
            ans[j] = arr[i];
            j++;
        }
        x[arr[i]] = 1;
    }
    printArray(ans, j);
    return 0;
}

void findArrayInteraction(int a1[], int a2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if

            (a1[i] == a2[j])
        {
            cout << a1[i] << " ";
            i++;
            j++;
        }
        else if (a1[i] < a2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}

void pairSum(int arr[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == val)
            {
                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }
}
void tripletSum(int arr[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {

                if (arr[i] + arr[j] + arr[k] == val)
                {
                    cout << arr[i] << " " << arr[j] << " " <<arr[k] << endl;
                }
            }
        }
    }
}

void sort01(int arr[],int size){
    int left =0,right=size-1;
    while(left<right){
        // if(arr[left]==1 && arr[right]==0){
        //     swap(arr[left],arr[right]);
        //        left++;
        // right--;
        // }
        // else if(arr[left]==1){
        //     right--;
        // } else if(arr[right]==0){
        //     left++;
        // }else{
        //     left++;
        //     right--;
        // }
        while(arr[left]==0) left++;
        while(arr[right]==1) right--;
        if(left<right){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
     
    }
}

void sort012(int arr[],int size){
    int left=0,mid=0,high=size-1;
    while(mid<=high){
        if(arr[mid]==0){
            // if(arr[mid]==arr[left]){
                // continue;
            // }
            swap(arr[mid],arr[left]);
                left++;
                mid++;
            
        }else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }else{
            mid++;
        }
        // printArray(arr,size);
    }
}


int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int arr1[4] = {4, 3, 2, 1};
    swapAlternate(arr, 5);
    swapAlternate(arr1, 4);
    // printArray(arr,5);
    // printArray(arr1,4);

    int arr2[5] = {3, 5, 3, 2, 2};
    // cout<<findUnique(arr2,5);

    int arr3[10] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 1};
    cout << boolalpha;
    // cout<<uniqueOccurace(arr3,10);
    int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 5, 1};
    // cout<<findDublicate(arr4,11);
    // int *arr5 = findAllDublicate(arr4,sizeof(arr4)/sizeof(int));
    // printArray(arr5,10);

    int arr6[] = {1, 2, 2, 2, 3, 4};
    int arr7[] = {2, 2, 3, 4};
    // findArrayInteraction(arr6,arr7,6,4);

    int arr8[] = {1, 2, 3, 5, 6,0,0};
    int size = sizeof(arr8) / sizeof(int);
    // pairSum(arr8, size, 8);
    // tripletSum(arr8,size,6);

    int arr9[] = {1,1,0,0,1,0,1,0,0};
    int size9 = sizeof(arr9) / sizeof(int);
    // sort01(arr9,size9);
    // printArray(arr9,size9);

      int arr10[] = {1,1,1,0,0,0,2,2,2};
    int size10 = sizeof(arr10) / sizeof(int);
    // sort012(arr10,size10);
    // printArray(arr10,size10);

    return 0;
}
