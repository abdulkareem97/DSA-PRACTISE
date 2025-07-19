// 257. Binary Tree Paths

// Given the root of a binary tree, return all root-to-leaf paths in any order.

// A leaf is a node with no children.

 

// Example 1:


// Input: root = [1,2,3,null,5]
// Output: ["1->2->5","1->3"]
// Example 2:

// Input: root = [1]
// Output: ["1"]

function preOrder(root,paths,t=[]){
    
    if(!root.left && !root.right){
        // t.push(root.val)
        paths.push([...t,root.val].join('->'))
    }
    t.push(root.val)
    if(root.left){
        preOrder(root.left,paths,t)
        t.pop()
    }
    if(root.right){
        preOrder(root.right,paths,t)
        t.pop()
    }
}
var binaryTreePaths = function(root) {
    let ans = []
    let j = 0
    preOrder(root,ans)
    return ans

};

// class Solution {
//     public:
//         void dfs(TreeNode* node ,string current,vector<string>& ans){
                
//                 current+=to_string(node->val);
    
//                 if(!node->left && !node->right){
//                     ans.push_back(current);
//                 }
//                 current+="->";
//                 if(node->left) dfs(node->left,current,ans);
//                 if(node->right) dfs(node->right,current,ans);
//                 current.pop_back();
//         }
//         vector<string> binaryTreePaths(TreeNode* root) {
//             vector<string> ans;
//             if(!root) return ans;
    
        
//             dfs(root,"",ans);
//             return ans;
//         }
//     };