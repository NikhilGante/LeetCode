#include <bits/stdc++.h>
using namespace std;


// One-pass (somehow slower) solution
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s;   // Keeps track of last index of height smaller than current
        int ans = 0, n = heights.size();
        for(int i = 0; i < n; i++){
            int start = i;
            while(!s.empty() && s.top().second > heights[i]){
                start = s.top().first;
                ans = max(ans, s.top().second * (i - s.top().first));
                s.pop();
            }
            s.push({start, heights[i]});
        }
        while(!s.empty()){
            ans = max(ans, s.top().second * (n - s.top().first));
            s.pop();
        }
        return ans;
    }
};

class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;   // Keeps track of last index of height smaller than current
        int ans = 0, n = heights.size();
        vector<int> maxL(n);    // Width of rectangle formed from i to left-hand side
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i])   s.pop();
            int w = i - (s.empty()? -1: s.top());
            maxL[i] = w;
            s.push(i);
        }
        while(!s.empty())   s.pop();
        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i])   s.pop();
            int area = heights[i] * (maxL[i] - 1 + (s.empty()? n : s.top()) - i);
            ans = max(ans, area);
            s.push(i);
        }
        return ans;
    }
};