// Factorials of large numbers
// Difficulty: MediumAccuracy: 36.57%Submissions: 158K+Points: 4Average Time: 20m
// Given an integer n, find its factorial. Return a list of integers denoting the digits that make up the factorial of n.

// Examples:

// Input: n = 5
// Output: [1, 2, 0]
// Explanation: 5! = 1*2*3*4*5 = 120
// Input: n = 10
// Output: [3, 6, 2, 8, 8, 0, 0]
// Explanation: 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800
// Input: n = 1
// Output: [1]
// Explanation: 1! = 1

#include <iostream>
#include <vector>
using namespace std;

vector<int> factorial(int n)
{
    // code here
    vector<int> ans = {1};
    if (n == 0 || n == 1)
    {
        return ans;
    }

    for (int i = 2; i <= n; i++)
    {
        int carry = 0;
        for (int j = 0; j < ans.size(); j++)
        {
            int digit = ans[j] * i + carry;
            ans[j] = digit % 10;
            carry = digit / 10;
        }
        while (carry)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
        }
    }
    int i = 0, j = ans.size() - 1;
    while (i < j)
    {
        swap(ans[i++], ans[j--]);
    }
    // sort(ans.begin(),ans.end());
    return ans;
}


void print(vector<int> ans){
    for(auto i:ans){
        cout<<i;
    }
    cout<<endl;
}

int main()
{
    print(factorial(100));
    return 0;
}
