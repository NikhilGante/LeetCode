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
        int goodNodes(TreeNode* root) {     // BFS Solution
            ios::sync_with_stdio(false);
            cin.tie(0);
            
            queue<pair<TreeNode*, int>> q;    // node, max
            q.push({root, INT_MIN});
            int ans = 0;
            while(!q.empty()){
                auto[cur, max_val] = q.front();
                q.pop();
                if(cur->val >= max_val){
                    max_val = cur->val;
                    ans++;
                }
                if(cur->left)   q.push({cur->left, max_val});
                if(cur->right)   q.push({cur->right, max_val});
            }
            return ans;
        }

        // Recursive Solution (dfs)
    /*
        int goodNodes(TreeNode* root) {
           return helper(root, INT_MIN);
        }
    
        int helper(TreeNode* root, int maximum){
            if(!root)    return 0;
            int val = 0;
            if(root->val >= maximum){
                val = 1;
                maximum = root->val;
            }
            return val + helper(root->left, maximum) + helper(root->right, maximum);
        }
    */
};