#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            ios::sync_with_stdio(false);
            cin.tie(0);
    
            vector<vector<int>> ans = {{}};
            vector<int> cur_set;
            cur_set.reserve(nums.size());
            sort(nums.begin(), nums.end());
            helper(nums, 0, cur_set, ans, true);
            return ans;
        }
        
        void helper(vector<int>& nums, int index, vector<int>& cur_set, vector<vector<int>>& ans, bool prev_null){
            if(index == nums.size()) return;
    
            helper(nums, index + 1, cur_set, ans, true);   
    
            if(index && nums[index] == nums[index - 1] && prev_null)  return;
            cur_set.push_back(nums[index]);
            ans.push_back(cur_set);
            helper(nums, index + 1, cur_set, ans, false);
            cur_set.pop_back();
        }
};