#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<string> digitToChar = {"abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        vector<string> ans;
        string cur;
        cur.reserve(digits.size());

        backtrack(digits, 0, cur, ans);
        return ans;
    }

    void backtrack(string& digits, int index, string& cur, vector<string>& ans){
        if(cur.size() == digits.size()){
            ans.push_back(cur);
            return;
        }

        for(char c: digitToChar[digits[index] - '2']){ // 3 unless cur is '7' or '9, then its 4
            cur.push_back(c);
            backtrack(digits, index + 1, cur, ans);
            cur.pop_back();
        }
    }
};