// Split the binary string into substrings with equal number of 0s and 1s
#include <iostream>
using namespace std;


int maxSubStr(string str){
    //Write your code here
    int ans = 0;
    int z = 0;
    int o = 0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='1') o++;
        else z++;
        if(o==z){
            ans++;
        }
    }
    // cout<<o<<" "<<z<<" ";
    if(o==z) return ans;
    return -1;
}

int main() {
    
    return 0;
}
