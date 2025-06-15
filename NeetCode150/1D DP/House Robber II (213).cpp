#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob1(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0, temp = 0;
        for(int i = 0; i < n; i++){
            temp = b;
            b = max(b, a + nums[i]);
            a = temp;
        }
        return b;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        int temp = nums[nums.size() - 1];
        nums.pop_back();
        int ans = rob1(nums);
        nums.push_back(temp);
        vector<int> copy(++nums.begin(), nums.end());
        return max(rob1(copy), ans);
    }
};