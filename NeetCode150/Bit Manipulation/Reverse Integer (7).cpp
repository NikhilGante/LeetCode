#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int reverse(int x) {
            int ans = 0;
            while(x){
                if(abs(ans) > INT_MAX /10) return 0;
                ans *= 10;
                ans += x % 10;
                x /= 10;
            }
            return ans;    
        }
};