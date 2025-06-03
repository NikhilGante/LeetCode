#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> cur_set;
            cur_set.reserve(nums.size());
            vector<bool> available(nums.size(), true);
            helper(nums, available, cur_set, ans);
            return ans;
        }
    
        void helper(vector<int>& nums, vector<bool>& available, vector<int>& cur_set, vector<vector<int>>& ans) {
            if(cur_set.size() == nums.size()){
                ans.push_back(cur_set);
                return;
            }
            for(int i = 0; i < nums.size(); i++){
                if(!available[i])  continue;
                cur_set.push_back(nums[i]);
                available[i] = 0;
                helper(nums, available, cur_set, ans);
                cur_set.pop_back();
                available[i] = 1;
            }
        }
};