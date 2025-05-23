#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int getSum(int a, int b) {
            // Bitwise addition
            int ans = 0, carry = 0;
            for(int i = 0; i < 32; i++){
                int _a = a & 1, _b = b & 1;
                a >>= 1;
                b >>= 1;
                int temp = _a ^ _b;
                ans |= (temp ^ carry) << i;
                carry = _a&_b | _a&carry | _b&carry;
                // carry = (temp & carry) | (_a & _b);   // if at least 2 out of 3 are 1, carry is 1
            }
            return ans;
        }
    };