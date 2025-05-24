#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n = nums.size();
            int calculated_sum = n*(n+1)/2, sum = 0;
            for(int i: nums)    sum += i;
            return calculated_sum - sum;
        }
        // Cool Bitwise Solution (but slower)
        /*
        int missingNumber(vector<int>& nums) {
            int n = nums.size();
            int ans = n;
            for(int i = 0; i < n; i++)    ans ^= (i ^ nums[i]);
            return ans;
        }
        */
};