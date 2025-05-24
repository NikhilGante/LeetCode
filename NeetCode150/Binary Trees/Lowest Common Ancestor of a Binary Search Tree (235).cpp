#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    public:
        // log(n) time, log(n) space (recursive solution)
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(!root)   return nullptr;

            int maximum = max(p->val, q->val), minimum = min(p->val, q->val);
            if(root->val > maximum)    return lowestCommonAncestor(root->left, p, q);
            if(root->val < minimum)     return lowestCommonAncestor(root->right, p, q);
            return root;
        }

        // Naive Solution (0(n)) - but works for any tree, not just binarily sorted (somehow, this ran faster)
        /*
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            return get<0>(containsNodes(root, p, q));   
        }
    
        tuple<TreeNode*, bool, bool> containsNodes(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(!root)   return {nullptr, false, false};
    
            tuple<TreeNode*, bool, bool> l = containsNodes(root->left, p, q);
            tuple<TreeNode*, bool, bool> r = containsNodes(root->right, p, q);
    
            if(get<0>(l))   return l;
            if(get<0>(r))   return r;
    
            bool has_p = root->val == p->val || get<1>(l) || get<1>(r);
            bool has_q = root->val == q->val || get<2>(l) || get<2>(r);
    
            return {(has_p && has_q ? root : nullptr), has_p, has_q};
        }
        */
};