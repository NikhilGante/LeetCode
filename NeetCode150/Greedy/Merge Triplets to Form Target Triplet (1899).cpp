#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a = target[0], b = target[1], c = target[2];
        bool _a = false, _b = false, _c = false;
        for(auto& trip: triplets){
            if(trip[0] == a && trip[1] <= b && trip[2] <= c)    _a = true;
            if(trip[1] == b && trip[0] <= a && trip[2] <= c)    _b = true;
            if(trip[2] == c && trip[0] <= a && trip[1] <= b)    _c = true;
            if(_a && _b && _c)  return true;
        }
        return false;
    }
};