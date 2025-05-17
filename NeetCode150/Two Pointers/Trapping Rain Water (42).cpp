#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            int max_l_arr[n];
            int ans = 0;

            int cur_max = 0;
            for (int l = 0; l < n; l++){
                max_l_arr[l] = cur_max;
                cur_max = max(cur_max, height[l]); 
            }

            cur_max = 0;
            for (int r = n - 1; r >= 0; r--){
                ans += max(min(cur_max, max_l_arr[r]) - height[r], 0);
                cur_max = max(cur_max, height[r]);
            }
            return ans;            
        }
};