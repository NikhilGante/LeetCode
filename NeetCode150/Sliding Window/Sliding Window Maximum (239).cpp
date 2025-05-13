#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n = nums.size();
            priority_queue<int> pq;
            vector<int> ans(nums.size() - k + 1);
            
            int l = 0, r = 0;
            for (; r < k; r++){
                pq.push(nums[r]);
            }
            ans[l] = pq.top();
            for(; r < nums.size(); r++){
                while(nums[r] > pq.top() && pq.size() > k - 1){
                    pq.push(nums[r]);
                }
                ans[l] = pq.top();
                l++;
            }
            return ans;         
        }
};