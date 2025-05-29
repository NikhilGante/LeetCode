#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            ios::sync_with_stdio(false);
            cin.tie(0);

            sort(candidates.begin(), candidates.end());
            vector<vector<int>> ans;
            vector<int> cur_set;
            helper(candidates, target, cur_set, 0, 0, ans);
            return ans;
        }
    
        void helper(vector<int>& candidates, int target, vector<int>& cur_set, int sum, int index, vector<vector<int>>& ans){
            if(sum == target)   ans.push_back(cur_set);
    
            for(int choice = index; choice < candidates.size(); choice++){
                if(sum + candidates[choice] > target)   break;  // because arr is sorted any future choice is also too big
                cur_set.push_back(candidates[choice]);
                helper(candidates, target, cur_set, sum + candidates[choice], choice, ans);
                cur_set.pop_back();
    
            }
        }
};