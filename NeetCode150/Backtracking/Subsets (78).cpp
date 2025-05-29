#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> ans;
            ans.reserve(pow(2, nums.size()));    
            vector<int> cur;
            dfs(nums, 0, cur, ans);
            return ans;
        }
        // Index is at the value to be added
        void dfs(vector<int>& nums, int index, vector<int>& cur, vector<vector<int>>& ans) {
            if(index == nums.size()){
                ans.push_back(cur);
                return;
            }
            cur.push_back(nums[index]);
            dfs(nums, index + 1, cur, ans);
            cur.pop_back();
            dfs(nums, index + 1, cur, ans);
        }
};