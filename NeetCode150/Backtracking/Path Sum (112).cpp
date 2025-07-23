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
        bool hasPathSum(TreeNode* root, int targetSum) {
            int curSum = 0;
            return dfs(root, targetSum, curSum);
        }
        bool dfs(TreeNode* root, int targetSum, int& curSum) {
            if(!root)   return false;
            curSum += root->val;
            if(curSum == targetSum && !(root->left || root->right)) return true;
    
            if(dfs(root->left, targetSum, curSum))  return true;
            if(dfs(root->right, targetSum, curSum))  return true;
            curSum -= root->val;
            return false;
        }
};