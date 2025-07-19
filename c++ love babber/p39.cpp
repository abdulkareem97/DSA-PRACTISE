#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// 46. Permutations - leetcode
void calculate(vector<int> &num, vector<vector<int>> &ans, int i)
{
    if (i == num.size())
    {
        // cout<<" called "<<endl;
        ans.push_back(num);
        return;
    }
    for (int j = i; j < num.size(); j++)
    {
        swap(num[i], num[j]);
        calculate(num, ans, i + 1);
        swap(num[i], num[j]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    calculate(nums, ans, 0);
    return ans;
}

// Permutations of a String - gfg

void calc(string &s, int i, vector<int> include, unordered_set<string> &ans, string output)
{
    if (i == s.size())
    {
        ans.insert(output);
        return;
    }

    for (int j = 0; j < s.size(); j++)
    {
        if (include[j] == 0)
        {
            include[j] = 1;
            output.push_back(s[j]);
            calc(s, i + 1, include, ans, output);
            output.pop_back();
            include[j] = 0;
        }
    }
}
vector<string> findPermutation(string &s)
{
    // Code here there
    unordered_set<string> ans;
    vector<int> include(s.size(), 0);
    calc(s, 0, include, ans, "");
    vector<string> ans1(ans.begin(), ans.end());
    return ans1;
}

int main()
{

    string s = "abc";
    vector<string> v = findPermutation(s);

    sort(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}
