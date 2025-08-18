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
// Note: The tree is not sorted
class Solution {
    public:
        int maxPathSum(TreeNode* root) {
            int ans = -1001;
            dfs(root, ans);
            return ans;
        }
        int dfs(TreeNode* root, int& ans){
            if(!root)   return -1001;
            int l = dfs(root->left, ans);   // left subtree best sum
            int r = dfs(root->right, ans);
            
            int best = max(root->val, max(l + root->val, r + root->val));
            ans = max(ans, max(max(best, max(l, r)), l + r + root->val));
            return best;
        }
    };