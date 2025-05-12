#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            if(s1.size() > s2.size())   return false;
            unordered_map<char, int> substr_freq, window_freq;
            int matches = 0; // How many letters of the window match the substr in frequency 

            for(char c: s1) substr_freq[c]++;

            int l = 0, r = 0;
            for(; r < s1.size(); r++) window_freq[s2[r]]++;

            for(const auto& p: window_freq){
                if(substr_freq.find(p.first) != substr_freq.end() && window_freq[p.first] == substr_freq[p.first]){
                    matches++;
                }
            }

            for(; r < s2.size(); r++){
                if(matches == substr_freq.size())   return true;

                char c = s2[r];
                window_freq[c]++;
                if(substr_freq.find(c) != substr_freq.end()){
                    if(window_freq[c] == substr_freq[c])    matches++;
                    else if(window_freq[c] == substr_freq[c] + 1)    matches--;
                }

                window_freq[s2[l]]--;
                if(substr_freq.find(s2[l]) != substr_freq.end()){
                    if(window_freq[s2[l]] == substr_freq[s2[l]])    matches++;
                    else if(window_freq[s2[l]] == substr_freq[s2[l]] - 1)    matches--;
                }

                l++;
            }
            return matches == substr_freq.size();
        }
};