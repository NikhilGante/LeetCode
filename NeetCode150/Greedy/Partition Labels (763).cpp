#include <bits/stdc++.h>
using namespace std;


class Solution2 {   // Initial O(n^2) solution
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int furthest = 0, n = s.size(), l = 0;

        for(int i = 0; i < n; i++){
            int r = n - 1;
            for(; s[r] != s[i]; r--);
            furthest = max(furthest, r);

            if(i >= furthest){
                ans.push_back(i - l + 1);
                l = i + 1;
            }
        }
        return ans;
    }
};
