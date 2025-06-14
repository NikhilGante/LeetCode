#include <bits/stdc++.h>
using namespace std;

// O(1) space sol
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0, temp = 0;
        for(int i = 0; i < n; i++){
            temp = b;
            b = max(b, a + nums[i]);
            a = temp;
        }
        return b;
    }
};

// O(n) space sol
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n + 2, 0);
        for(int i = 2; i < n + 2; i++){
            ans[i] = max(ans[i - 1], ans[i - 2] + nums[i - 2]);
        }
        return ans[n + 1];
    }
};
*/