#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            ios::sync_with_stdio(false);
            cin.tie(0);

            sort(intervals.begin(), intervals.end());
            vector<vector<int>> ans;
            ans.reserve(intervals.size());
            ans.push_back(intervals[0]);

            for (int i = 1; i < intervals.size(); i++){
                if(intervals[i][0] <= ans.back()[1])    ans.back()[1] = max(ans.back()[1], intervals[i][1]);   // Merge
                else    ans.push_back(intervals[i]);    // Create new
            }
            return ans;
        }
};