#include <bits/stdc++.h>
using namespace std;

class Solution {    // Idea: We compare adjacent elements and if the 2nd is higher, add it to the answer
    public:
        int maxProfit(vector<int>& prices) {
            int ans = 0;
            for(int i = 1; i < prices.size(); i++){
                ans += max(prices[i] - prices[i-1], 0);
            }
            return ans;
    }
};