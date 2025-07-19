#include <iostream>
using namespace std;

bool isPalindrome(string s){
    // cout<<s<<endl;
    int st=0,end=s.size()-1;
    while(st<end){
        if(s[st]!=s[end]) return false;
        st++;
        end--;
    }
    return true;
}
string longestPalindrome(string s) {
    // code here
    int start = 0;
    int end = 1;
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            if(end<j-i+1 && isPalindrome(s.substr(i,j-i+1)) ){
                start = i;
                end = j-i+1;
            }
        }
    }
    return s.substr(start,end);
}


int main() {
    string q("aaaabbaa");

    cout<<longestPalindrome(q)<<endl;

    string test("abcd");
    cout<<test.substr(1);


    
    return 0;
}
