#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> ans;
            vector<int> cur_set;
            cur_set.reserve(candidates.size());
            helper(candidates, target, cur_set, 0, -1, ans);
            return ans;
        }
    
        void helper(vector<int>& candidates, int target, vector<int>& cur_set, int sum, int index, vector<vector<int>>& ans){
            if(sum == target){
                ans.push_back(cur_set);
                return;
            }
    
            for(int choice = index + 1; choice < candidates.size(); choice++){
                if(sum + candidates[choice] > target)   return;
                if(choice > index + 1 && candidates[choice] == candidates[choice - 1])  continue;
                cur_set.push_back(candidates[choice]);
                helper(candidates, target, cur_set, sum + candidates[choice], choice, ans);
                cur_set.pop_back();
    
            }
    
        }
};