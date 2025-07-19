// Parenthesis Checker

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isBalanced(string& s) {
    // code here
    stack<char> st;
    unordered_map<char,char> m;
    m['{'] = '}';
    m['('] = ')';
    m['['] = ']';
    for(char c:s){
        if(c=='(' || c=='[' || c=='{'){
            st.push(c);
        }else{
            if(!st.empty() && m[st.top()]==c){
                st.pop();
            }else{
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    
    return 0;
}
