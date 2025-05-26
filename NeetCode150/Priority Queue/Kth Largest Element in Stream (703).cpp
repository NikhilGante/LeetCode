#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    public:
        int mK;
        priority_queue<int, vector<int>, greater<int>> pq;
        KthLargest(int k, vector<int>& nums) {
            mK = k;
            for(int i: nums)    pq.push(i);
            while(pq.size() > k)    pq.pop();
        }
        
        int add(int val) {
            if(pq.size() < mK){
                pq.push(val);
            }
            else if(val > pq.top()){
                pq.pop();
                pq.push(val);
            }
            return pq.top();
        }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */