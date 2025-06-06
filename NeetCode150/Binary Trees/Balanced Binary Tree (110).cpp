#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            bool balanced = true;
            dfs(root, balanced);
            return balanced;
        }
    
        int dfs(TreeNode* root, bool& balanced){  // return depth
            if(!root)   return 0;
    
            int l = dfs(root->left, balanced);
            int r = dfs(root->right, balanced);
    
            balanced &= abs(l - r) <= 1;
            return 1 + max(l, r);
        }  
};