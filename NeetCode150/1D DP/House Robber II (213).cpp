#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int rob1(vector<int>& nums, int start, int end) {
        int a = 0, b = 0, temp = 0;
        for(int i = start; i < end; i++){
            temp = b;
            b = max(b, a + nums[i]);
            a = temp;
        }
        return b;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        int ans = rob1(nums, 0, nums.size() - 1);
        return max(rob1(nums, 1, nums.size()), ans);
    }
};  