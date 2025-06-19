#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int furthest = -1;
        int n = nums.size();
        vector<int> dp(n, 10001);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            if(i + nums[i] > furthest){
                int prev_furthest = furthest;
                furthest = i + nums[i];
                for(int j = prev_furthest + 1; j <= min(n - 1, furthest); j++){
                    dp[j] = min(dp[j], dp[i] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};