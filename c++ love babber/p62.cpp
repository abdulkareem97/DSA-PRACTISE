// binary tree

#include <iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }

};



Node* createBinaryTree(vector<int> &arr,int &i){
    Node* temp = new Node(arr[i]);
    i = i+1;
    if(i<arr.size() && arr[i]!=-1){
        cout<<" "<<temp->data<<" -> "<<arr[i];
        temp->left = createBinaryTree(arr,i);
    }
    i=i+1;
    if(i<arr.size() && arr[i]!=-1){
        
        cout<<" "<<temp->data<<" -> "<<arr[i];
        temp->right = createBinaryTree(arr,i);
    }
    return temp;
}

void levelOrderTraversal(Node* root){
    if(!root) return;
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);
    cout<<" level 1 :- ";
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        if(!temp){
            if(q.empty()) continue;
            cout<<endl<<" level 2 :- ";
            q.push(nullptr);
            continue;
        }
        cout<<" "<<temp->data;
        if(temp->left){
            
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

}
void reverseLevelOrderTraversal(Node* root){
    if(!root) return;
    queue<Node *> q;
    stack<int> s;
    q.push(root);
    q.push(nullptr);
    // s.push(root->data);
    // s.push(-1);
    int level = 1;
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        if(!temp){
            if(q.empty()) continue;
            // cout<<endl<<" level 2 :- ";
            level++;
            s.push(-1);
            q.push(nullptr);
            continue;
        }
        // cout<<" "<<temp->data;
        s.push(temp->data);
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            
            q.push(temp->left);
        }
     
    }
  
    cout<<" level "<<level<<" :- ";
    while(!s.empty()){
        if(s.top()==-1){
            level--;
            cout<<endl<<" level "<<level<<" :- ";
        }else{
            cout<<" "<<s.top();
        }
        s.pop();
    }

}

void preOrder(Node* root){
    if(!root) return;

    cout<<" "<<root->data;
    preOrder(root->left);
    preOrder(root->right);
}
// post and in


Node * buildFromLevelOrder(vector<int> arr){
    queue<Node *> q;
    // q.push(arr[i])
    Node * temp = new Node(arr[0]);
    Node * ans = temp;
    q.push(temp);
    int i=1;
    while(!q.empty()){
      Node * temp = q.front();
      q.pop();
      if(i<arr.size() && arr[i]!=-1){
        temp->left = new Node(arr[i]);
        q.push(temp->left);
      }
      i++;
      if(i<arr.size() && arr[i]!=-1){
        temp->right = new Node(arr[i]);
        q.push(temp->right);
      }
      i++;

        


    }
    return ans;
}

// count leaf node

int noOfLeafNodes(Node *root){
    // Write your code here.
    int count = 0;
    if(!root) return 0;
    if(!root->left && !root->right){
        return 1;
    }
    
    count = noOfLeafNodes(root->left) + noOfLeafNodes(root->right);
    return count;
}


int main() {

    vector<int> arr = {1,3,7,-1,-1,11,-1,-1,5,17,-1,-1,-1};
    // arr= {1,2,3};
    int i=0;
    Node* root = createBinaryTree(arr,i);
    cout<<endl;
    // preOrder(root);
    // levelOrderTraversal(root);
    cout<<endl;
    // reverseLevelOrderTraversal(root);

    vector<int> arr1 = {1,3,5,7,11,17};
    Node* root1= buildFromLevelOrder(arr1);
    levelOrderTraversal(root1);
    
    return 0;
}
