#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end());
            vector<vector<int>> ans;
            ans.reserve(intervals.size());
    
            int cur_start = intervals[0][0], cur_end = intervals[0][1];
            for(const auto& i: intervals){
                if(i[0] <= cur_end) cur_end = max(cur_end, i[1]);   // Merge
                else{   // Create new
                    ans.push_back({cur_start, cur_end});
                    cur_start = i[0], cur_end = i[1];
                }
            }
            // Push last interval
            if(ans.empty() || ans[ans.size() - 1][1] != cur_end)   ans.push_back({cur_start, cur_end});
            return ans;
        }
};