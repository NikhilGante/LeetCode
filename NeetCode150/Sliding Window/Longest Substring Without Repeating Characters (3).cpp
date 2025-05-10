#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_set<char> set;
            int ans = 0;
            for(int r = 0; r < s.size(); r++){
                if(set.find(s[r]) != set.end()){    // Already exists in map
                    ans = max<int>(ans, set.size());
                    for(int i = r - set.size(); s[i] != s[r]; i++)  set.erase(s[i]);
                }
                set.insert(s[r]);  // Replace with new instance of s[r] in set
            }
            return max<int>(ans, set.size());
        }
};