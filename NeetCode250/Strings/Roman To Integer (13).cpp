#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, int> m = {
        {'I', 1}, 
        {'V', 5}, 
        {'X', 10}, 
        {'L', 50}, 
        {'C', 100}, 
        {'D', 500}, 
        {'M', 1000}, 
    };

    int romanToInt(string s) {
        int ans = 0, last = 0;
        for(char c: s){
            if(last >= m[c]) ans += last;
            else ans -= last;
            last = m[c];
        }
        return ans + last;
    }
};