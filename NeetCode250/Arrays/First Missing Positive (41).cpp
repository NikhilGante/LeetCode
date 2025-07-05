#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -1 or < 0 -> "holes", 0 -> occupied
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)    if(!nums[i]) nums[i] = -1;
        nums.push_back(-1);
        for(int i = 0; i < nums.size(); i++){
            int j = nums[i];
            if(j > 0) nums[i] = -1;   // Mark as empty
            while(j > 0 && j < nums.size()){
                int temp = nums[j];
                nums[j] = 0;    // Mark as occupied
                j = temp;
            }
        }
        for(int i = 1; i < nums.size(); i++)    if(nums[i] < 0) return i;
        return nums.size();
    }

};