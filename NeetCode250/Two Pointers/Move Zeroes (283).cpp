#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int w = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r]){
                nums[w] = nums[r];
                w++;
            }
        }
        for(;w < nums.size(); w++)  nums[w] = 0;
    }
};