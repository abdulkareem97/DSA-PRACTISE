// 2D Array

#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool search(int arr[3][4], int ele)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (ele == arr[i][j])
            {
                return true;
            }
        }
    }
    return false;
}

void printSumRowWise(int arr[3][4])
{
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += arr[i][j];
        }
        cout << " " << sum;
    }
}

void printSumColumnWise(int arr[3][4])
{
    for (int i = 0; i < 4; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[j][i];
        }
        cout << " " << sum;
    }
}

// Largest Row Sum Value
int printLargestSumRow(int arr[3][4])
{
    int m = 0;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += arr[i][j];
        }
        m = max(m, sum);
        // cout<<" "<<sum;
    }
    return m;
}

//  Print Like A Wave - cn
void print(vector<int> v)
{
    for (auto i : v)
    {
        cout << " " << i;
    }
}

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    // Write your code here
    vector<int> v;
    bool s = true;
    for (int i = 0; i < mCols; i++)
    {
        for (int j = 0; j < nRows; j++)
        {
            if (s)
            {
                v.push_back(arr[j][i]);
            }
            else
            {
                v.push_back(arr[nRows - j - 1][i]);
            }
        }
        s = !s;
    }
    return v;
}

// 48. Rotate Image
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
        // break;
    }
}

// 74. Search a 2D Matrix
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int r = matrix.size();
    int c = matrix[0].size();
    int left = 0;
    int right = r * c - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (matrix[mid / c][mid % c] == target)
            return true;
        if (matrix[mid / c][mid % c] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

// 240. Search a 2D Matrix II
bool searchMatrix2(vector<vector<int>> &matrix, int target)
{
    int r = matrix.size();
    int c = matrix[0].size();
    int i = r - 1, j = 0;
    while (i > -1 && j < c)
    {
        if (matrix[i][j] == target)
            return true;
        if (matrix[i][j] < target)
            j++;
        else
            i--;
    }
    return false;
}

void spiralPrint(vector<vector<int>> arr)
{
    int count = 0;
    vector<int> v;
    int endingRow = arr.size();
    int endingCol = arr[0].size();
    int total = (endingRow) * (endingCol);
    int startingRow = 0;
    int startingCol = 0;
    while (count < total)
    {

        // adding first row
        for (int index = startingCol; index < endingCol; index++)
        {
            v.push_back(arr[startingRow][index]);
            count++;
        }
        if (count >= total)
        {
            break;
        }
        startingRow++;
        // adding last column
        for (int index = startingRow; index < endingRow; index++)
        {
            v.push_back(arr[index][endingCol - 1]);
            count++;
        }
        endingCol--;
        if (count >= total)
        {
            break;
        }

        // adding last row
        for (int index = endingCol - 1; index >= startingCol; index--)
        {
            v.push_back(arr[endingRow - 1][index]);
            count++;
        }
        endingRow--;
        if (count >= total)
        {
            break;
        }
        // adding first column
        for (int index = endingRow - 1; index >= startingRow; index--)
        {
            v.push_back(arr[index][startingCol]);
            count++;
        }
        startingCol++;
        if (count >= total)
        {
            break;
        }
        // break;
    }
    // return v;
}

int main()
{

    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<" "<<arr[i][j];
    //     }
    //     cout<<endl;
    // }

    cout << boolalpha;
    // cout<<search(arr,0);
    // printSumRowWise(arr);
    // cout<<endl;
    // printSumColumnWise(arr);
    // cout<<endl;
    // cout<<printLargestSumRow(arr);
    int arr1[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    // spiralPrint(arr1);

    map<int, int> m;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    // m.insert(1,2);
    // m.insert(2,2);
    // m.insert(3,2);
    for (auto i : m)
    {
        cout << " " << i.first;
    }
    m.erase(1);
    m[1] = 0;
    for (auto i : m)
    {
        cout << " " << i.first;
    }

    return 0;
}