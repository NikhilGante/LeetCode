#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> count;
            for(int num: nums)  count[num]++;
    
            vector<vector<int>> buckets (nums.size());  // Count, value
            for(const auto& [k, v]: count)  buckets[v - 1].push_back(k);
    
            vector<int> ans(k);
            int ans_count = 0;
            for(int i = buckets.size() - 1; i >= 0; i--){
                for(int j: buckets[i]){
                    ans[ans_count] = j;
                    ans_count++;
                    if(ans_count == k)  return ans;
                }
            } 
            return ans;
    
        }
};