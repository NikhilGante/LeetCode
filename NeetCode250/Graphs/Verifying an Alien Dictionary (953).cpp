#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> order_mp(26, 0);
        for(int i = 0; i < 26; i++) order_mp[order[i] - 'a'] = i;

        for(int i = 0; i < words.size() - 1; i++){
            string& a = words[i], b = words[i + 1];
            bool is_prefix = true;   // if b is a prefix of a
            for(int j = 0; j < min(a.size(), b.size()); j++){
                if(a[j] != b[j]){
                    is_prefix = false;
                    if(order_mp[a[j] - 'a'] > order_mp[b[j] - 'a']) return false;
                    break;
                }
            }
            if(is_prefix && b.size() < a.size())    return false;
        }
        return true;
    }
};