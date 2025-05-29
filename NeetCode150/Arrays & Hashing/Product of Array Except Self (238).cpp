#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int pro = 1, n = nums.size();
            vector<int> ans(n);
            for (int i = 0; i < n; i++){    // Product of elements left of i
                ans[i] = pro;
                pro *= nums[i];
            }
            pro = 1;
            for (int i = n - 1; i >= 0; i--){   // Same but for right
                ans[i] *= pro;
                pro *= nums[i];
            }
            return ans;
        }
    };