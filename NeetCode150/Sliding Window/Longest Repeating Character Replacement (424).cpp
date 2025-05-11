#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int characterReplacement(string s, int k) {
            int l = 0, ans = 0, max_freq = 0;
            unordered_map<char, int> freq;  // frequency of each char in our window
            
            for(int r = 0; r < s.size(); r++){
                freq[s[r]]++;
                max_freq = max(max_freq, freq[s[r]]);
                if((r - l + 1) - max_freq > k){ // Window no longer valid, must update l
                    freq[s[l]]--;
                    l++;
                }
                ans = max(r - l + 1, ans);
            }
            return ans;
        }
};