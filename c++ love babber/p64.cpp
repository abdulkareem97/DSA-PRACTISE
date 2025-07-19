// traversal problems of binary tree

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// 103. Binary Tree Zigzag Level Order Traversal
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    int level = 1;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {

        int s = q.size();
        vector<int> v(s);
        for (int i = 0; i < s; i++)
        {
            TreeNode *temp = q.front();
            if (level % 2 == 1)
            {
                v[i] = temp->val;
            }
            else
            {
                v[s - i - 1] = temp->val;
            }

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);

            q.pop();
        }
        level++;
        ans.push_back(v);
    }
    return ans;
}

// Tree Boundary Traversal
void leftTraversal(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        //   ans.push_back(root->data);
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        leftTraversal(root->left, ans);
    }
    else
    {
        leftTraversal(root->right, ans);
    }
}
void childTraversal(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
        return;
    }

    childTraversal(root->left, ans);
    childTraversal(root->right, ans);
}
void rightTraversal(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        //   ans.push_back(root->data);
        return;
    }
    if (root->right)
    {
        rightTraversal(root->right, ans);
    }
    else
    {
        rightTraversal(root->left, ans);
    }
    ans.push_back(root->data);
}
vector<int> boundaryTraversal(Node *root)
{
    // code here
    vector<int> ans;
    if (!root)
        return ans;
    ans.push_back(root->data);
    if (!root->left && !root->right)
    {

        return ans;
    }
    leftTraversal(root->left, ans);
    childTraversal(root, ans);
    rightTraversal(root->right, ans);
    return ans;
}


// 87. Vertical Order Traversal of a Binary Tree
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> m;
    queue<pair<int, TreeNode *>> q;
    q.push(make_pair(0, root));
    int mini = 0, maxi = 0;
    while (!q.empty())
    {

        int s = q.size();
        unordered_map<int, int> c;
        for (int i = 0; i < s; i++)
        {
            pair<int, TreeNode *> temp = q.front();
            q.pop();
            m[temp.first].push_back(temp.second->val);
            c[temp.first]++;

            if (c[temp.first] > 1)
            {
                // cout<<" "<<temp.second->val<<" "<< m[temp.first].size()<< " "<<c[temp.first]<<" "<< endl;

                sort(m[temp.first].begin() + m[temp.first].size() - c[temp.first], m[temp.first].end());
            }
            // st.insert(temp.first);
            if (temp.second->left)
                q.push(make_pair(temp.first - 1, temp.second->left));
            if (temp.second->right)
                q.push(make_pair(temp.first + 1, temp.second->right));
            mini = min(mini, temp.first);
            maxi = max(maxi, temp.first);
        }
    }
    for (int i = mini; i <= maxi; i++)
    {
        ans.push_back(m[i]);
    }

    return ans;
}


// Top View of Binary Tree
vector<int> topView(Node *root) {
    // code here
    vector<int> ans;
    queue<pair<int,Node *>> q;
    q.push(make_pair(0,root));
    unordered_map<int,int> m;
    int mini=0,maxi=0;
    while(!q.empty()){
        // pair<int,Node *> p = q.front
        int s = q.size();
        for(int i=0;i<s;i++){
             pair<int,Node *> p = q.front();
             q.pop();
             if(!m[p.first])
             m[p.first]=p.second->data;
             if(p.second->left) q.push(make_pair(p.first-1,p.second->left));
             if(p.second->right) q.push(make_pair(p.first+1,p.second->right));
             mini = min(mini,p.first);
             maxi = max(maxi,p.first);
        }
    }
    for(int i=mini;i<=maxi;i++){
        ans.push_back(m[i]);
    }
    return ans;
    
}

// Bottom View of Binary Tree
vector <int> bottomView(Node *root) {
    // Your Code Here
    vector<int> ans;
    queue<pair<int,Node*>> q;
    q.push(make_pair(0,root));
    unordered_map<int,int> m;
    int mini=0,maxi=0;
    while(!q.empty()){
        int s = q.size();
        for(int i=0;i<s;i++){
            pair<int,Node*> p = q.front();
            q.pop();
            m[p.first] = p.second->data;
            if(p.second->left) q.push(make_pair(p.first-1,p.second->left));
            if(p.second->right) q.push(make_pair(p.first+1,p.second->right));
            mini = min(mini,p.first);
            maxi = max(maxi,p.first);
        }
    }
    for(int i=mini;i<=maxi;i++){
        ans.push_back(m[i]);
    }
    return ans;
}


// Right View of Binary Tree
vector<int> rightView(Node *root)
{
   // Your Code here
   queue<Node *> q;
   q.push(root);
   vector<int> ans;
   while(!q.empty()){
       int s = q.size();
      for(int i=0;i<s;i++){
           Node* temp = q.front();
           q.pop();
          if(i==s-1) ans.push_back(temp->data);
           if(temp->left) q.push(temp->left);
           if(temp->right) q.push(temp->right);
      }
   }
   return ans;
}


// Left View of Binary Tree
vector<int> leftView(Node *root) {
    // code here
    vector<int> ans;
    if(!root) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int s = q.size();
        for(int i=0;i<s;i++){
            Node* temp = q.front();
            q.pop();
            if(i==0) ans.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return ans;
}


// Diagonal Tree Traversal
vector<int> diagonal(Node *root) {
    // code here
    queue<Node*> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty()){
        
        Node* temp = q.front();
        q.pop();
  
        while(temp){
        if(temp->left){
            q.push(temp->left);
        }
            ans.push_back(temp->data);
            temp = temp->right;
        }
        
    }
    return ans;
}

int main()
{

    return 0;
}
