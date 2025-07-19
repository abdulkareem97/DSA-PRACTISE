// Two sum -Pairs with 0 Sum
// Difficulty: EasyAccuracy: 31.49%Submissions: 469K+Points: 2Average Time: 20m
// Given an integer array arr, return all the unique pairs [arr[i], arr[j]] such that i != j and arr[i] + arr[j] == 0.

// Note: The pairs must be returned in sorted order, the solution array should also be sorted, and the answer must not contain any duplicate pairs.

// Examples:

// Input: arr = [-1, 0, 1, 2, -1, -4]
// Output: [[-1, 1]]
// Explanation: arr[0] + arr[2] = (-1)+ 1 = 0.
// arr[2] + arr[4] = 1 + (-1) = 0.
// The distinct pair are [-1,1].
// Input: arr = [6, 1, 8, 0, 4, -9, -1, -10, -6, -5]
// Output: [[-6, 6],[-1, 1]]
// Explanation: The distinct pairs are [-1, 1] and [-6, 6].

#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

  vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        // set<vector<int>> s;
        unordered_map<int,int> m;
        vector<vector<int>> v;
        for(int i=0;i<arr.size();i++){
            // int remain = 
            if(m[-arr[i]] && !m[arr[i]]){
                // s.insert({-arr[i],arr[i]});
                v.push_back({-abs(arr[i]),abs(arr[i])});
            }
            m[arr[i]]++;
            // cout<<" "<<m[arr[i]]<<" "<<m[-arr[i]]<<endl; 
        }
        sort(v.begin(),v.end());
        if(m[0]>1){
            v.push_back({0,0});
        }
        return v;
    }

int main() {
    
    return 0;
}
