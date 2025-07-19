#include <iostream>
using namespace std;


// Palindrome String
bool isPalindrome(string& s) {
    // code here
    int l=0,r=s.size()-1;
    while(l<r){
        if(s[l++]!=s[r--]) return false;
    }
    return true;
}

int main() {
    
    return 0;
}
