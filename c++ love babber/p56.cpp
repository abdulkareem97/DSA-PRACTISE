// leetcode problems on stack

#include <iostream>
using namespace std;

// Next Smaller Element

#include<stack>
#include<vector>
#include <climits>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for(int i=n-1;i>=0;i--){
        int cur = arr[i];
       
        while(s.top()>=cur){
            s.pop();
        }
        ans[i] = s.top();
        s.push(cur);
    }
    return ans;
}


// 84. Largest Rectangle in Histogram

vector<int> prevSmaller(vector<int>& arr){
    stack<int> s;
    vector<int> ans(arr.size());
    s.push(-1);
    for(int i=0;i<arr.size();i++){
        while(s.top()!=-1 && arr[s.top()]>=arr[i]){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> nextSmaller(vector<int>& arr){
    stack<int> s;
    vector<int> ans(arr.size());
    s.push(-1);
    for(int i=arr.size()-1;i>=0;i--){
        while(s.top()!=-1 && arr[s.top()]>=arr[i]){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int>& heights) {
    vector<int> prev,next;

    prev = prevSmaller(heights);
    next = nextSmaller(heights);
    int ans = INT_MIN;
    for(int i=0;i<heights.size();i++){
        int l = heights[i];
        if(next[i]==-1){
            next[i]=heights.size();
        }
        int b = next[i]-prev[i]-1;
        ans = max(ans,l*b);
    }
    return ans;
    
}

void print(vector<int> ans){
    for(auto i:ans){
        cout<<" "<<i;
    }
}

int main() {
    vector<int> v = {2,4,1,3};
    print(nextSmallerElement(v,v.size()));

    
    return 0;
}
