// subset leetcode / subsequence coding ninjas
#include <iostream>
#include <vector>
using namespace std;

void calculate(vector<int> &nums, int n, int i, vector<int> output, vector<vector<int>> &ans)
{
    if (i == n)
    {
        ans.push_back(output);
        for(auto k:output){
            cout<<k;
        }
        cout<<" ";
        return;
    }

    calculate(nums, n, i + 1, output, ans);
    output.push_back(nums[i]);
    calculate(nums, n, i + 1, output, ans);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> output;
    vector<vector<int>> ans;
    calculate(nums, nums.size(), 0, output, ans);
    return ans;
}

int main()
{
    vector<int> v = {1,2,3};

    subsets(v);

    return 0;
}