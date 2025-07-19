// Word Break
// Difficulty: MediumAccuracy: 40.86%Submissions: 132K+Points: 4
// Given a string s and a dictionary of n words dictionary, find out if "s" can be segmented into a space-separated sequence of dictionary words.
// Return 1 if it is possible to break the s into a sequence of dictionary words, else return 0. 

// Note: From the dictionary dictionary each word can be taken any number of times and in any order.

// Examples :

// Input: n = 6, s = "ilike", dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
// Output: 1
// Explanation: The string can be segmented as "i like".
// Input: n = 6, s = "ilikesamsung", dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
// Output: 1
// Explanation: The string can be segmented as "i like samsung" or "i like sam sung".

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

   
int wordBreak(int n, string s, vector<string> &dictionary) {
    //code here
    
      if(s.empty()) return 1;
    for(int i=1;i<=s.size();i++){
        string sub = s.substr(0,i);
        if(find(dictionary.begin(),dictionary.end(),sub)!=dictionary.end() && wordBreak(n,s.substr(i),dictionary)  ) return 1;
    }
    return 0;
}

int main() {
    
    return 0;
}
