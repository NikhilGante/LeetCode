#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n = nums.size();
            priority_queue<int> pq;
            unordered_map<int, int> non_window_freq;   // (val, num_occurences)
            vector<int> ans(nums.size() - k + 1);
            
            int l = 0, r = 0;
            for (; r < k; r++)  pq.push(nums[r]);
            ans[l] = pq.top();
            for (; r < nums.size(); r++){
                non_window_freq[nums[l]]++;
                while(non_window_freq[pq.top()]){
                    non_window_freq[pq.top()]--;
                    pq.pop();
                }
                pq.push(nums[r]);
                l++;
                ans[l] = pq.top();
            }
            return ans;         
        }
};