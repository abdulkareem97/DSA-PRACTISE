// 125. Valid Palindrome

#include <iostream>
using namespace std;

bool getAns(string s,int start,int end){
    if(start>end) return true;

    if(iswalnum(s[start]) && iswalnum(s[end])){
        // cout<<s[start]<<" "<<s[end]<<endl;
        if(tolower(s[start])==tolower(s[end])){
            return getAns(s,start+1,end-1);
        }else{
            return false;
        }
    }else if(!iswalnum(s[start])){
        return getAns(s,start+1,end);
    }else if(!iswalnum(s[end])){
        return getAns(s,start,end-1);
    }
    return false;

}
bool isPalindrome(string s) {
    return getAns(s,0,s.size()-1);

}

int main() {
    
    return 0;
}
