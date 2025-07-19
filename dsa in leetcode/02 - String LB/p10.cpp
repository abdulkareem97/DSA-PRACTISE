// String Subsequence Game


#include <iostream>
#include<set>
using namespace std;

bool match(string s){
    string vowel = "aeiou";
    if(vowel.find(s[0])!=string::npos && vowel.find(s[s.size()-1])==string::npos) return true;
    return false;
}
  void recursive(string s,string cur,set<string> &ans){
      if(s.empty()){
        cout<<cur<<" ";
          if(match(cur)) ans.insert(cur);
          return;
      }
      recursive(s.substr(1),cur+s[0],ans);
      recursive(s.substr(1),cur,ans);
  }
  set<string> allPossibleSubsequences(string S) {
      // code here
      set<string> ans;
      recursive(S,"",ans);
      return ans;
  }


int main() {
    string s("axxzxy");
    allPossibleSubsequences(s);
    
    return 0;
}
