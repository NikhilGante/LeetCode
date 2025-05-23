#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int mySqrt(int x) {
            int l = 0, r = x;
            while(l <= r){
                long mid = (l + r) / 2;
                if(mid*mid > x) r = mid - 1;
                else if(mid*mid < x)    l = mid + 1;
                else return mid;
            }
            return l - 1;   // last valid mid value (mid^2 < x)
        }
};  
