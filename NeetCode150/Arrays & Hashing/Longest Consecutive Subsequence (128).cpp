#include <bits/stdc++.h>
using namespace std;

// Idea: We construct "chains" of connected sequences, updating the length of the chain as we do so
class Solution {
    public:
    
    // Inefficient set solution
    /*
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
    */
    
    // "Better" Hash Map solution
    /*
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i: nums){   
            if(!mp[i]){ // Skip if this is a duplicate
                mp[i] = mp[i - 1] + mp[i + 1] + 1;  // New chain length = left len + right len + 1
                mp[i - mp[i-1]] = mp[i];    // Update length of leftmost element of new chain
                mp[i + mp[i+1]] = mp[i];    // Update length of rightmost element of new chain
                ans = max(ans, mp[i]);
            }
        }
        return ans;
    }
    */
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s (nums.begin(), nums.end());
        int ans = 0;
        for(int i: s){
            if(s.find(i - 1) == s.end()){   // Find beginning of sequence
                int count = 1;
                while(s.find(i + count) != s.end()) count++;
                ans = max(ans, count);    
            }
        }
        return ans;
    }


};
