#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            gen(ans, "(", n, 1);
            return ans;
        }
    
        void gen(vector<string>& ans, const string& str, int n, int open) {
            if(2*n - str.size()){
                if(n - open)    gen(ans, str + "(", n, open + 1); 
                if(str.size() < 2*open)        gen(ans, str + ")", n, open); // if there's room for another closed brace
            }
            else{
                ans.push_back(str);
            }
        }
};
