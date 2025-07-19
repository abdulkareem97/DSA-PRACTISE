// Spirally traversing a matrix
// Difficulty: MediumAccuracy: 35.2%Submissions: 306K+Points: 4
// You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.

// Examples:

// Input: mat[][] = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
// Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
// Explanation:

// Input: mat[][] = [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18]]
// Output: [1, 2, 3, 4, 5, 6, 12, 18, 17, 16, 15, 14, 13, 7, 8, 9, 10, 11]
// Explanation: Applying same technique as shown above.
// Input: mat[][] = [[32, 44, 27, 23], [54, 28, 50, 62]]
// Output: [32, 44, 27, 23, 62, 50, 28, 54]
// Explanation: Applying same technique as shown above, output will be [32, 44, 27, 23, 62, 50, 28, 54].
// Constraints:
// 1 <= n, m <= 1000
// 0 <= mat[i][j]<= 100

#include <iostream>
#include <vector>
using namespace std;
vector<int> spirallyTraverse(vector<vector<int>> &mat)
{
    // code here
    vector<int> v;
    int sc = 0, sr = 0, er = mat.size() - 1, ec = mat[0].size() - 1;
    int total = mat.size() * mat[0].size();
    int count = 0;
    while (count < total)
    {
        for (int i = sc; i <= ec; i++)
        {
            v.push_back(mat[sr][i]);
            count++;
        }
        if (count >= total)
        {
            break;
        }
        sr++;
        for (int i = sr; i <= er; i++)
        {
            v.push_back(mat[i][ec]);
            count++;
        }
        ec--;
        if (count >= total)
        {
            break;
        }

        for (int i = ec; i >= sc; i--)
        {
            v.push_back(mat[er][i]);
            count++;
        }
        er--;
        if (count >= total)
        {
            break;
        }
        for (int i = er; i >= sr; i--)
        {
            v.push_back(mat[i][sc]);
            count++;
        }
        sc++;
    }
    return v;
}

int main()
{

    return 0;
}
