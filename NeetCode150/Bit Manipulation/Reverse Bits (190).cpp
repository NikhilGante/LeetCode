#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            int ans = 0;
            for(int i = 0; i < 32; i++){
                char r = n & 1;
                n >>= 1;
                ans |= (r << (31 - i));
            }
            return ans;
        }
};