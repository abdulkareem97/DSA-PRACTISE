// Longest Prefix Suffix
// Difficulty: HardAccuracy: 27.91%Submissions: 143K+Points: 8
// Given a string of characters s, find the length of the longest prefix which is also a suffix.
// Note: Prefix and suffix can be overlapping but they should not be equal to the entire string.

// Examples :

// Input: s = "abab"
// Output: 2
// Explanation: "ab" is the longest prefix and suffix. 
// Input: s = "aabcdaabc"
// Output: 4
// Explanation: The string "aabc" is the longest prefix and suffix.
// Input: s = "aaaa"
// Output: 3
// Explanation: "aaa" is the longest prefix and suffix. 


#include <iostream>
#include<vector>
using namespace std;



int longestPrefixSuffix(string &s) {
    // Your code goes here
    vector<int> lps(s.size());
    
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while(i<s.size()){
        if(s[i]==s[len]){
            lps[i++] = ++len;
        }else{
            if(len!=0){
                len = lps[len-1];
            }else{
                lps[i++] = len;
            }
        }
    }
    return lps[lps.size()-1];
}

int main() {
    
    return 0;
}
