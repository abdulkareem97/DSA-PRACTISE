#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};



// Height of Binary Tree
int height(Node* node) {
    // code here
    if(!node) return 0;
    int count =0;
    if(node->left || node->right){
        return 1 + max(height(node->left),height(node->right));
    }
    return 0;
}



// Diameter of a Binary Tree
pair<int,int> diameterFast(Node * root){
    pair<int,int> p;
    if(!root) return make_pair(0,0);
    pair<int,int> op1 = diameterFast(root->left);
    pair<int,int> op2 = diameterFast(root->right);
    int op3 = op1.second + op2.second + 1;
    p.second = max(op1.second,op2.second)+1;
    p.first = max(op1.first,max(op2.first,op3));
    return p;
    
    
}
int diameter(Node* root) {
    // Your code here
    return diameterFast(root).first-1;
}



// Balanced Tree Check
pair<bool,int> isBalancedFast(Node* root){
    if(!root){
        return make_pair(true,0);
    }
    pair<bool,int> left = isBalancedFast(root->left);
    pair<bool,int> right = isBalancedFast(root->right);
    int h = max(left.second,right.second) + 1;
    bool ans = abs(left.second-right.second)<=1;
    // pair.second = height;
    if(left.first && right.first && ans){
        return make_pair(true,h);
    }else{
        return make_pair(false,h);
        
    }
}
bool isBalanced(Node* root) {
    // Code here
    return isBalancedFast(root).first;
    
    
}


// Identical Trees
bool isIdentical(Node *r1, Node *r2) {
    // Your Code here
    if(!r1 && !r2){
        return true;
    }
    if(!r1 || !r2){
        return false;
    }
    if(r1->data==r2->data){
        return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
    }
    return false;
}


// Sum Tree
pair<bool,int> isSumTreeFast(Node * root){
    if(!root) return make_pair(true,0);
    if(!root->left && !root->right) return make_pair(true,root->data);
    pair<bool,int> left = isSumTreeFast(root->left);
    pair<bool,int> right = isSumTreeFast(root->right);
    bool cond = root->data == left.second + right.second;
    if(left.first && right.first && cond){
        return make_pair(true,2*root->data);
    }
    return make_pair(false,root->data);
}

  bool isSumTree(Node* root) {
      // Your code here
      
      // if(!root->left || !root->right) return false;
      
      return isSumTreeFast(root).first;
  }

int main() {
    
    return 0;
}
