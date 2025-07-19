#include <iostream>
#include<vector>
using namespace std;


void reverseString(vector<char>& s) {
    int l=0,r=s.size()-1;
    while(l<r){
        swap(s[l++],s[r--]);
    }
}


int main() {
    
    return 0;
}
