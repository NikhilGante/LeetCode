#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> s(nums.begin(), nums.end());
            int ans = 0;
            for(int i: nums){
                if(s.find(i) == s.end())    continue;
                s.erase(i);
                int below = 0;
                while(s.find(i - below - 1) != s.end()){
                    s.erase(i - below - 1);
                    below++;
                }
                int above = 0;
                while(s.find(i + above + 1) != s.end()){
                    s.erase(i + above + 1);
                    above++;
                }
                ans = max(below + above + 1, ans);
            }
            return ans;
        }
    };