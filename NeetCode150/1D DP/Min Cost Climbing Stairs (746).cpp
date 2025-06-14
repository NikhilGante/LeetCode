#include <bits/stdc++.h>
using namespace std;

// O(1) space solution
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = 0, b = 0, temp = 0;
        for(int i = 2; i < cost.size() + 1; i++){
            temp = b;
            b = min(cost[i - 1] + b, cost[i - 2] + a);
            a = temp;
        }
        return b;
    }
};

// O(n) space sol
/*
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> ans(n + 1);
        ans[0] = ans[1] = 0;
        for(int i = 2; i <= n; i++){
            ans[i] = min(cost[i - 1] + ans[i - 1], cost[i - 2] + ans[i - 2]);
        }
        return ans[n];
    }
};
*/