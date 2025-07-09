#include <bits/stdc++.h>
using namespace std;

// O(n) time and O(m) space
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> w_freq, target_freq;  // freq of char in window
        for(char c: t)  target_freq[c]++;
        int freq_met = 0, freq_req = target_freq.size();
        int l = 0, r = -1;  // Window is [l, r] (inclusive)
        int ans_len = 0, ans_l = 0;

        while(l < (s.size() - t.size() + 1) && r < (int)s.size()){
            if(freq_met < freq_req){
                r++;
                w_freq[s[r]]++;
                if(target_freq[s[r]] && w_freq[s[r]] == target_freq[s[r]])   freq_met++;
            }
            else{
                int win_len = r - l + 1;
                if(ans_len == 0 || win_len < ans_len){
                    ans_len = win_len;
                    ans_l = l;
                }
                // Shrink window
                if(target_freq[s[l]] && w_freq[s[l]] == target_freq[s[l]]) freq_met--;
                w_freq[s[l]]--;
                l++;
            }
        }
        return s.substr(ans_l, ans_len);
    }
};