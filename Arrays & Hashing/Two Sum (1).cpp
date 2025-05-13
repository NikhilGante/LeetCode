#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> positions;  // Value, index 
            for(int i = 0; i < nums.size(); i++){
                if(positions.find(target - nums[i]) != positions.end()){
                    return {i, positions[target - nums[i]]};
                }
                positions[nums[i]] = i;
            }
            return {0, 0};
        }
    };