#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Construct Tree from Inorder & Preorder
// Function to build the tree from given inorder and preorder traversals
Node *solveBuildTree(vector<int> &inorder, vector<int> &preorder, unordered_map<int, int> &m, int &p, int start, int end)
{

    if (p >= preorder.size())
        return nullptr;
    Node *temp = new Node(preorder[p]);
    int index = m[preorder[p]];
    int left = index - start;
    int right = end - index;
    p++;
    if (left > 0)
    {
        temp->left = solveBuildTree(inorder, preorder, m, p, start, index - 1);
    }
    if (right > 0)
    {
        temp->right = solveBuildTree(inorder, preorder, m, p, index + 1, end);
    }

    return temp;
}
Node *buildTree(vector<int> &inorder, vector<int> &preorder)
{
    // code here
    unordered_map<int, int> m;
    int p = 0;
    for (int i = 0; i < inorder.size(); i++)
    {
        m[inorder[i]] = i;
    }
    return solveBuildTree(inorder, preorder, m, p, 0, preorder.size() - 1);
}



// Binary Tree from Inorder and Postorder
// Function to return a tree created from postorder and inoreder traversals.

Node *solveBuildTreePost(vector<int> &inorder, vector<int> &postorder, int &pos, unordered_map<int, int> &m, int start, int end)
{
    if (pos < 0)
        return nullptr;
    Node *temp = new Node(postorder[pos]);
    int index = m[postorder[pos]];
    pos--;
    int left = index - start;
    int right = end - index;
    // cout<<"for "<<temp->data<<" left "<<left<<" right "<<right<<" index "<<index<<" "<<m[1] <<endl;
    if (right > 0)
    {
        temp->right = solveBuildTreePost(inorder, postorder, pos, m, index + 1, end);
        // cout<<" right data for "<<temp->data<<" "<<temp->right->data<<endl;
    }
    if (left > 0)
    {
        temp->left = solveBuildTreePost(inorder, postorder, pos, m, start, index - 1);
        // cout<<" left data for "<<temp->data<<" "<<temp->left->data<<endl;
    }

    return temp;
}
Node *buildTree(vector<int> inorder, vector<int> postorder)
{
    // code here
    unordered_map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
    {
        m[inorder[i]] = i;
    }
    int pos = postorder.size() - 1;
    return solveBuildTreePost(inorder, postorder, pos, m, 0, inorder.size() - 1);
}

int main()
{

    return 0;
}
