// Strings Rotations of Each Other


#include <iostream>
#include<vector>
using namespace std;


void getLps(string &s,vector<int> &lps){
    int i=1,len=0;
    while(i<s.size()){
        if(s[i]==s[len]){
            lps[i++] = ++len;
        }else{
            if(len!=0){
                len = lps[len-1];
            }else{
                lps[i++]=0;
            }
        }
    }
    
}
bool areRotations(string &s1, string &s2) {
    // Your code here
    if(s1.size()!=s2.size()) return false;
    vector<int> lps(s1.size(),0);
    getLps(s2,lps);
    int i=0,j=0;
    string s = s1+s1;
    int n = s.size();
    while(i<n){
        if(s[i]==s2[j]){
            i++;
            j++;
            if(j==s2.size()) return true;
        }else{
            if(j!=0) j = lps[j-1];
            else i++;
        }
    }
    return false;
    
    
}


void print(auto v){
    for(auto i:v){
        cout<<" "<<i;
    }
    cout<<endl;
}

// answer using built in function
// s1+=s1;
// return s1.find(s2)!=string::npos;

int main() {

    string s = "aabaababab";
    vector<int> lps(s.size(),0);
    getLps(s,lps);
    print(lps);
    
    return 0;
}
