// 38. Count and Say
#include <iostream>
using namespace std;


string rle(string s){
    string ans="";
    int i=0;
    while(i<s.size()){
        // ans+=s[i];
        int j=i;
        while(j<s.size() && s[j]==s[i] ) j++;
        int len = j-i;
        ans += to_string(len)+s[i];
        i=j;


    }
    return ans;
}
string countAndSay(int n) {
    string ans="1";
    for(int i=1;i<n;i++){
        ans = rle(ans);
    }
    return ans;
}


int main() {
    cout<<countAndSay(5);
    return 0;
}
