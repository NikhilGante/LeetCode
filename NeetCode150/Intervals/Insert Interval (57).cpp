#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            if(intervals.empty())   return {newInterval};
            vector<vector<int>> ans;
            ans.reserve(intervals.size() + 1);
            int i;
            for(i = 0; i < intervals.size() && intervals[i][1] < newInterval[0]; i++){
                ans.push_back(intervals[i]);
            }
            if(i >= intervals.size() || intervals[i][0] > newInterval[1]) ans.push_back(newInterval);
            else{
                ans.push_back({min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])});
                ++i;
            }
            for(; i < intervals.size(); i++){
                if(intervals[i][0] <= ans.back()[1])    ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                else ans.push_back(intervals[i]);
            }
            return ans;
    
    
        }
};