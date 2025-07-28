#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalTime = 0, curTime = customers[0][0];
        for(int i = 0; i < customers.size(); i++){
            double arrTime = customers[i][0], cookTime = customers[i][1];
            curTime = cookTime + max(curTime, arrTime);
            totalTime += curTime - arrTime;
        }
        return totalTime/customers.size();
    }
};