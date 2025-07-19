#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;
    Tree(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Tree *buildTree(vector<int> &v, int &i)
{
    Tree *root = new Tree(v[i]);
    i = i + 1;
    if (i < v.size() && v[i] != -1)
    {
        root->left = buildTree(v, i);
    }
    i = i + 1;
    if (i < v.size() && v[i] != -1)
    {
        root->right = buildTree(v, i);
    }
    return root;
}

void levelOrderTraversal(Tree *root)
{
    queue<Tree *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();
        if (!temp)
        {
            cout << endl;
            if (!q.empty())
                q.push(nullptr);
        }
        else
        {
            cout << " " << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void levelOrderTraversalReverse(Tree *root)
{
    queue<Tree *> q;
    stack<int> st;
    q.push(root);
    q.push(nullptr);
    // st.push(root->data);
    // st.push(-1);
    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();
        if (!temp)
        {
            cout << endl;
            if (!q.empty())
            {
                st.push(-1);
                q.push(nullptr);
            }
        }
        else
        {
            cout << " " << temp->data << " ";
            st.push(temp->data);
            if (temp->right)
            {
                q.push(temp->right);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
        }
    }

    while (!st.empty())
    {
        if (st.top() == -1)
            cout << endl;
        else
            cout << " " << st.top() << " ";
        st.pop();
    }
}

Tree *createByLevelOrderTraversal(vector<int> &v)
{
    queue<Tree *> q;
    Tree *root = new Tree(v[0]);
    q.push(root);
    int i = 0;
    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();
        i = i + 1;
        if (i < v.size() && v[i] != -1)
        {
            temp->left = new Tree(v[i]);
            q.push(temp->left);
        }
        i = i + 1;
        if (i < v.size() && v[i] != -1)
        {
            temp->right = new Tree(v[i]);
            q.push(temp->right);
        }
    }
    return root;
}

void preOrder(Tree *root)
{
    if (!root)
        return;

    cout << " " << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void preOrderIterative(Tree *root)
{
    if (!root)
        return;

    stack<Tree *> st;
    st.push(root);
    while (root || !st.empty())
    {
        if (!root)
        {
            root = st.top();
            root = root->right;
            st.pop();



             if (root)
                st.push(root);
            
        }
        else
        {
            cout << " " << root->data << " ";
            root = root->left;
            if (root)
                st.push(root);
        }
    }
}
void inorder(Tree *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << " " << root->data << " ";
    inorder(root->right);
}
void inorderIterative(Tree *root)
{
    if (!root)
        return;

    stack<Tree *> st;
    st.push(root);
    while (root || !st.empty())
    {
        if (!root)
        {
            root = st.top();
            st.pop();
            cout << " " << root->data << " ";
            root = root->right;
            if (root)
                st.push(root);
        }
        else
        {

            root = root->left;
            if (root)
                st.push(root);
        }
    }
}
void postorder(Tree *root)
{
    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << " " << root->data << " ";
}
void postorderIterative(Tree *root)
{
    if (!root)
        return;

    stack<Tree *> st;
    Tree *cur = root;
    // st.push(root);
    while (cur || !st.empty())
    {
        if (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            Tree *temp = st.top()->right;
            
            if (!temp)
            {
                temp = st.top();
                cout << " " << temp->data << " ";
                // temp = st.top()->right;.
                st.pop();
                while (!st.empty() && st.top()->right == temp)
                {
                    cout << " " << temp->data << " ";
                    temp = st.top()->right;
                    st.pop();
                }
            }
            else
            {
                cur = temp;
                // st.push(cur);
            }
        }
    }
}

int main()
{
    vector<int> v{1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    int i = 0;
    // Tree *root = buildTree(v, i);
    v = {1, 3, 5, 7, 11, 17, 19};
    Tree *root = createByLevelOrderTraversal(v);

    cout << " post order traversal of a tree " << endl;
    preOrder(root);
    cout << endl;
    preOrderIterative(root);
    // levelOrderTraversalReverse(root);
    cout << endl
         << " happy ending";
    return 0;
}
