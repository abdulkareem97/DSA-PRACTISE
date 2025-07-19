
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// The Celebrity Problem
int celebrity(vector<vector<int> >& mat) {
    // code here
    stack<int> s;
    for(int i=0;i<mat.size();i++){
        s.push(i);
    }
    while(s.size()>1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(mat[a][b]){
            s.push(b);
        }else if(mat[b][a]){
            s.push(a);
        }
    }
    if(s.empty()) return -1;
    int ans = s.top();
    for(int i=0;i<mat.size();i++){
        if(mat[ans][i]) return -1;
    }
    for(int i=0;i<mat.size();i++){
        if(ans!=i && !mat[i][ans]) return -1;
    }
    return ans;
}

// Max rectangle
vector<int> nextSmaller(vector<int> &mat){
    stack<int> s;
    vector<int> ans(mat.size());
    s.push(-1);
    for(int i=mat.size()-1;i>=0;i--){
        while(s.top()!=-1 && mat[s.top()]>=mat[i]){
            s.pop();
        }
        
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmaller(vector<int> &mat){
    stack<int> s;
    vector<int> ans(mat.size());
    s.push(-1);
    for(int i=0;i<mat.size();i++){
        while(s.top()!=-1 && mat[s.top()]>=mat[i]){
            s.pop();
        }
        
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}


int maxAreaInHisto(vector<int> &mat){
    vector<int> prev,next;
    prev = prevSmaller(mat);
    next = nextSmaller(mat);
    int ans = INT_MIN;
    for(int i=0;i<mat.size();i++){
        if(next[i]==-1) next[i]=mat.size();
        int len = mat[i];
        int b = next[i]-prev[i]-1;
        ans = max(ans,len*b);
    }
    return ans;
}
int maxArea(vector<vector<int>> &mat) {
    // Your code here
    int ans = maxAreaInHisto(mat[0]);
    for(int i=1;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            if(mat[i][j]){
                mat[i][j] += mat[i-1][j];
            }
        }
        ans = max(ans,maxAreaInHisto(mat[i]));
    }
    return ans;
}


int main() {
    
    return 0;
}
