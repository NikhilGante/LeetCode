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
        int diameterOfBinaryTree(TreeNode* root) {
            int ans = 0;
            helper(root, ans);
            return ans;
        }
        int helper(TreeNode* root, int& ans) {  // Returns depth
            if(!root) return 0;
            int l = helper(root->left, ans), r = helper(root->right, ans);
            ans = max(ans, l + r);
            return 1 + max(l, r);
        }
    };