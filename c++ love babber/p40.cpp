// Rat in a Maze Problem - I

#include <iostream>
#include <vector>
// #include<algorithm>
using namespace std;

void solve(vector<vector<int>> &mat, int i, int j, int n, string output, vector<string> &ans)
{
    if (i == n - 1 && j == n - 1)
    {
        // cout<< " i "
        ans.push_back(output);
        return;
    }
    if (i < 0 || j < 0 || i >= n || j >= n)
    {
        return;
    }

    // cout << " i " << i << " j " << j << endl;

    if (mat[i][j])
    {
        mat[i][j]=0;
             output.push_back('D');
        solve(mat, i + 1, j, n, output, ans);
        output.pop_back();
                output.push_back('L');
        solve(mat, i, j - 1, n, output, ans);
        output.pop_back();
        output.push_back('R');
        solve(mat, i, j + 1, n, output, ans);
        output.pop_back();
        output.push_back('U');
        solve(mat, i - 1, j, n, output, ans);
        output.pop_back();

   
        mat[i][j]=1;
    }
}
vector<string> findPath(vector<vector<int>> &mat)
{
    // code here
    vector<string> ans;
    int n = mat.size();
    if (mat[n - 1][n - 1] == 0)
        return ans;
    solve(mat, 0, 0, n, "", ans);
    // sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> s=findPath(mat);
    for(auto i:s){
        cout<<i<<" ";
    }

        return 0;
}
