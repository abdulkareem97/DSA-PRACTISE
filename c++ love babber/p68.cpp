//

#include <vector>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to return a list containing the inorder traversal of the tree.
// Morris traversal for Inorder

vector<int> inOrder(Node *root)
{
    // Your code here
    vector<int> ans;
    while (root)
    {

        if (!root->left)
        {
            ans.push_back(root->data);
            root = root->right;
            continue;
        }

        Node *temp = root->left;
        while (temp->right && temp->right != root)
        {
            temp = temp->right;
        }
        if (temp->right)
        {
            temp->right = nullptr;
            ans.push_back(root->data);
            root = root->right;
        }
        else
        {
            temp->right = root;
            root = root->left;
        }
    }
    return ans;
}

// Flatten binary tree to linked list
Node *preOrder(Node *root)
{
    if (!root)
        return nullptr;
    if (!root->left && !root->right)
        return root;
    Node *left = preOrder(root->left);
    Node *right = preOrder(root->right);
    root->right = left;
    while (left && left->right)
    {
        left = left->right;
    }
    if (left)
        left->right = right;
    else
        root->right = right;
    root->left = nullptr;
    return root;
}

void method2(Node *root)
{
    Node *cur = root;
    while (cur)
    {
        if (cur->left)
        {
            Node *temp = cur->left;
            while (temp->right)
                temp = temp->right;
            temp->right = cur->right;

            cur->right = cur->left;
            cur->left = nullptr;
        }
        cur = cur->right;
    }
}
void flatten(Node *root)
{
    // preOrder(root);

    // moris traversal
    method2(root);
}

int main()
{

    return 0;
}
