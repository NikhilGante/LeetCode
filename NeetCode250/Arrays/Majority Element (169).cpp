#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0], num_maj = 1;    // Current candidate guess
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != maj){
                num_maj--;
                if(!num_maj){
                    maj = nums[i];  // new candidate
                    num_maj = 1;
                }
            }
            else num_maj++;
        }
        return maj;
    }
};