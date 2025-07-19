// Chocolate Distribution Problem
// Difficulty: EasyAccuracy: 49.91%Submissions: 246K+Points: 2Average Time: 15m
// Given an array arr[] of positive integers, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets among m students such that -
//       i. Each student gets exactly one packet.
//      ii. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum and return that minimum possible difference.

// Examples:

// Input: arr = [3, 4, 1, 9, 56, 7, 9, 12], m = 5
// Output: 6
// Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following m packets :[3, 4, 9, 7, 9].
// Input: arr = [7, 3, 2, 4, 9, 12, 56], m = 3
// Output: 2
// Explanation: The minimum difference between maximum chocolates and minimum chocolates is 4 - 2 = 2 by choosing following m packets :[3, 2, 4].
// Input: arr = [3, 4, 1, 9, 56], m = 5
// Output: 55
// Explanation: With 5 packets for 5 students, each student will receive one packet, so the difference is 56 - 1 = 55.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int findMinDiff(vector<int>& a, int m) {
    // code here
    sort(a.begin(),a.end());
    int res = a[a.size()-1];
    for(int i=0;i<=a.size()-m;i++){
        res = min(res,a[m-1+i]-a[i]);
    }
    return res;
    // return a[m-1]-a[0];
}

int main() {
    
    return 0;
}
