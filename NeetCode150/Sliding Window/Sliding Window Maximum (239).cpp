#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1);
        deque<int> d;

        int l = 0;
        for (int r = 0; r < nums.size(); r++){
            while(!d.empty() && nums[r] > nums[d.back()])  d.pop_back();    // Pop old values if less than new value

            d.push_back(r);
            if(!d.empty() && r - d.front() + 1 > k)    d.pop_front();   // make sure window doesn't exceed size

            if(r >= k - 1){ // Fill answer array
                ans[l] = nums[d.front()];   // Front of deque should always hold the max val in the window
                l++;
            }            
        }
        return ans;               
    }

        // Old solution (suboptimal - uses priority queue)
        /*
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
        */
};