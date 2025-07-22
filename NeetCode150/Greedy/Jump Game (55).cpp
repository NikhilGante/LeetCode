#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest = 0;
        for(int i = 0; i <= furthest; i++){
            furthest = max(i + nums[i], furthest);
            if(furthest >= nums.size() - 1) return true;
        }
        return false;
    }
};