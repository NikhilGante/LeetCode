#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int c = 0; c < s.size()/2; c++){
            char temp = s[c];
            s[c] = s[s.size() - c - 1];
            s[s.size() - c - 1] = temp;
        }
    }
};