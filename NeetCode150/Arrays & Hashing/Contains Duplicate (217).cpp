
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> s;
            for(int i: nums){
                if(s.find(i) != s.end()){
                    return true;
                }
                s.insert(i);
            }
            return false;
        }
};

/* Slower but less code:

    #include <bits/stdc++.h>
    using namespace std;
    class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            return unordered_set(nums.begin(), nums.end()).size() < nums.size();
        }
    };
*/