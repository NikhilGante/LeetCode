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
        // Top Down solution (better - exits as soon as tree is found to be invalid)
        bool isValidBST(TreeNode* root) {
            return dfs(root, LONG_MIN, LONG_MAX);
        }

        // track min of right and max of left
        bool dfs(TreeNode* root, long left, long right){
            if(!root)   return true;
            if(root->val <= left || root->val >= right) return false;
            return dfs(root->left, left, root->val) && dfs(root->right, root->val, right);
        }

    /*  // Bottom Up Solution (bad because it checks all n nodes before answering false)
        bool isValidBST(TreeNode* root) {
            return get<0>(dfs(root));
        }
        // track min of right and max of left
    
        tuple<bool, long long, long long> dfs(TreeNode* root){
            if(!root)   return {true, LLONG_MAX, LLONG_MIN};
    
            auto l = dfs(root->left);
            auto r = dfs(root->right);
    
            if(!get<0>(l) || !get<0>(r))  return {false, LLONG_MAX, LLONG_MIN};
    
            bool valid = (root->val > get<2>(l) && root->val < get<1>(r));
            long long min_val = min((long long)root->val, min(get<1>(l), get<1>(r)));
            long long max_val = max((long long)root->val, max(get<2>(l), get<2>(r)));
            return {valid, min_val, max_val};
        }
    */
};