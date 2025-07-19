// Permutations of a String


#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void permutation(string &s,int pos,vector<string> &ans,unordered_set<string> & st){
    if(pos>=s.size()){
        if(!st.count(s))
        ans.push_back(s);
        st.insert(s);
        return;
    }
    for(int i=pos;i<s.size();i++){
        swap(s[i],s[pos]);
        permutation(s,pos+1,ans,st);
        swap(s[i],s[pos]);
    }
}
  vector<string> findPermutation(string &s) {
      // Code here there
      vector<string> ans;
      unordered_set<string> st;
      permutation(s,0,ans,st);
      return ans;
  }


int main() {
    
    return 0;
}
