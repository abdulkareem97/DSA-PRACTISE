// Selection sort

#include <iostream>
#include <vector>
using namespace std;

// Function to perform selection sort on the given array.
void selectionSort(vector<int> &arr)
{
    // code here
    for (int i = 0; i < arr.size(); i++)
    {
        int ele = arr[i];
        int k = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (ele > arr[j])
            {
                ele = arr[j];
                k = j;
            }
        }
        swap(arr[k], arr[i]);
    }
}

int main()
{

    return 0;
}
