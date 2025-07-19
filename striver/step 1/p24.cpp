// Sum of first n terms
// Difficulty: BasicAccuracy: 23.17%Submissions: 178K+Points: 1
// Given an integer n, calculate the sum of series 13 + 23 + 33 + 43 + … till n-th term.

// Examples:

// Input: n = 5
// Output: 225
// Explanation: 13 + 23 + 33 + 43 + 53 = 225
// Input: n = 7
// Output: 784
// Explanation: 13 + 23 + 33 + 43 + 53 + 63 + 73 = 784

#include <iostream>
using namespace std;

int sumOfSeries(int n) {
    // code here
    int sum =0;
    if(n==1) return 1;
    sum = n*n*n + sumOfSeries(n-1);
    return sum;
}

int main() {
    
    return 0;
}
