#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            if(s1.size() > s2.size())   return false;
            unordered_map<char, int> substr_freq, window_freq;
            unordered_map<char, vector<int>> window_locations;
            int window_matching_count = 0; // How many letters of the window match the substr in frequency 

            for(char c: s1) substr_freq[c]++;

            for(int r = 0; r < s2.size(); r++){
                char c = s2[r];
                window_freq[c]++;
                window_locations[c].push_back(r);

                bool found = substr_freq.find(c) != substr_freq.end();
                if(!found){   // window no longer matches, have to reset
                    window_freq.clear();
                    window_locations.clear();
                    window_matching_count = 0;
                }
                else if(window_freq[c] > substr_freq[c]){   // Window freq exceeds substr_freq for character c 
                    int first_index = window_locations[c][0];
                    window_freq.clear();
                    window_locations.clear();
                    window_matching_count = 0;
                    for(int i = first_index + 1; i <= r; i++){
                        window_freq[s2[i]]++;
                        window_locations[s2[i]].push_back(i);
                        if(found && window_freq[s2[i]] == substr_freq[s2[i]])   window_matching_count++;
                    }
                }
                else if(found && window_freq[c] == substr_freq[c])   window_matching_count++; // "Normal" case: char found in substr
                
                if(window_matching_count == substr_freq.size())   return true;
            }
            return false;
        }
};