#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};



// Sum of nodes on the longest path
void solve(Node* root,int sum,int len,int &maxSum,int &maxLen){
    if(!root){
        if(maxLen<len){
            maxSum = sum;
            maxLen = len;
        }else if(maxLen==len){
            maxSum = max(sum,maxSum);
        }
        return;
    }
    sum += root->data;
    solve(root->left,sum,len+1,maxSum,maxLen);
    solve(root->right,sum,len+1,maxSum,maxLen);
}
int sumOfLongRootToLeafPath(Node *root) {
    // code here
    int len = 0;
    int sum = 0;
    solve(root,0,0,sum,len);
    return sum;
}


// LCA in Binary Tree
int solveLca(Node* root,int n1,int n2,Node* &ans){
    if(!root){
        return 0;
    }
    int val = 0;
    if(root->data==n1 || root->data==n2){
        val = 1;
    }
    val += solveLca(root->left,n1,n2,ans) + solveLca(root->right,n1,n2,ans);
    if(val==2){
        ans = root;
        return 0;
    }
    return val;
}
Node* lca(Node* root, int n1, int n2) {
    // Your code here
    Node* ans = nullptr;
    solveLca(root,n1,n2,ans);
    return ans;
}



// K Sum Paths
int solveSumK(Node *root,int k,int curSum,unordered_map<int,int> &m){
    if(!root) return 0;
    
    int paths = 0;
    curSum += root->data;
    if(curSum==k)
        paths++;
    
    paths += m[curSum-k];
    
    
    m[curSum]++;
    paths+= solveSumK(root->left,k,curSum,m);
    paths+= solveSumK(root->right,k,curSum,m);
    
    m[curSum]--;
    return paths;
    
}
int sumK(Node *root, int k) {
    // code here
    unordered_map<int,int> m;
    return solveSumK(root,k,0,m);
    
}


// Kth Ancestor in a Tree
int solveKthAncesttor(Node *root,int k,int node,int &ans){
    if(!root) return 0;
    if(root->data==node){
        return 1;
    }
    int val = max(solveKthAncesttor(root->left,k,node,ans),solveKthAncesttor(root->right,k,node,ans));
    if(val==k) ans = root->data;
    if(val) return val+1;
    
    return val;
    
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ans = -1;
    solveKthAncesttor(root,k,node,ans);
    return ans;
    
}


//Maximum sum of Non-adjacent nodes
    
pair<int,int> solveGetMaxSum(Node* root){
    if(!root) return {0,0};
    
    pair<int,int> left = solveGetMaxSum(root->left);
    pair<int,int> right = solveGetMaxSum(root->right);
    pair<int,int> res;
    res.first = root->data + left.second + right.second;
    res.second = max(left.first,left.second) + max(right.first,right.second);
    return res;
    
}
int getMaxSum(Node *root) 
{
    // Add your code here
    pair<int,int> p=solveGetMaxSum(root);
    return max(p.first,p.second);
}


int main() {
    
    return 0;
}
