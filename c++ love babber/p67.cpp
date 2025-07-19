
// Burning Tree


#include <iostream>
#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


int burnTree(Node *root,unordered_map<Node*,Node*> &m){
    int ans = 0;
    queue<Node*> q;
    q.push(root);
    unordered_map<Node*,bool> visited;
    visited[root] = true;
      while(!q.empty()){
          int s = q.size();
          bool flag = false;
          for(int i=0;i<s;i++){
              Node* temp = q.front();
              q.pop();
              if(m[temp] && !visited[m[temp]]){
                  q.push(m[temp]);
                  visited[m[temp]] = true;
                  flag = true;
              }
              if(temp->left && !visited[temp->left]){
                  q.push(temp->left);
                  visited[temp->left] = true;
                  flag = true;
              }
              if(temp->right && !visited[temp->right]){
                  q.push(temp->right);
                  visited[temp->right] = true;
                  flag = true;
              }
          }
          if(flag) ans++;
      }
    
    
    return ans;
}
  int minTime(Node* root, int target) {
      // code here

      unordered_map<Node*,Node*> m;        
      queue<Node*> q;
      q.push(root);
      m[root] = nullptr;
      Node* targetNode = nullptr;
      while(!q.empty()){
          int s = q.size();
          for(int i=0;i<s;i++){
              Node* temp = q.front();
              q.pop();
              if(temp->data==target){
                 targetNode = temp;
              }
              if(temp->left){
                  q.push(temp->left);
                  m[temp->left] = temp;
              }
              if(temp->right){
                  q.push(temp->right);
                  m[temp->right] = temp;
              }
              
              
          }
      }
      return burnTree(targetNode,m);
  }


int main() {
    
    return 0;
}
