// Recursion with strings

#include <iostream>
using namespace std;

string reversString(string &s,int i=0){
        string x = "";
        if(s.size()-1==i){
            return x+s[i];
        }
        
        return reversString(s,i+1)+s[i];

}
void reversStringInPlace(string &s,int i,int j){
    if(i<j){
        swap(s[i],s[j]);
        reversStringInPlace(s,i+1,j-1);
        // cout<< " here";
    }

}

int main() {
    string s = "abcde";
    // cout<< reversString(s,0);
    reversStringInPlace(s,0,s.size()-1);
    cout<< s;

    return 0;
}