#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            if(s1.size() > s2.size())   return false;
            vector<int> substr_freq(26), window_freq(26);

            int matches = 0; // How many letters of the window match the substr in frequency 
            int l = 0, r = 0;
            
            for(; r < s1.size(); r++){
                substr_freq[s1[r] - 'a']++;
                window_freq[s2[r] - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                if(window_freq[i] == substr_freq[i])    matches++;
            }

            for(; r < s2.size(); r++){
                if(matches == 26)   return true;

                char c = s2[r] - 'a';
                window_freq[c]++;
                if(window_freq[c] == substr_freq[c])    matches++;
                else if(window_freq[c] == substr_freq[c] + 1)    matches--;

                c = s2[l] - 'a';
                window_freq[c]--;
                if(window_freq[c] == substr_freq[c])    matches++;
                else if(window_freq[c] == substr_freq[c] - 1)    matches--;

                l++;
            }
            return matches == 26;
        }
};