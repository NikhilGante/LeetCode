#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> small;  // max heap
    priority_queue<int, vector<int>, greater<int>> large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        if(!large.empty() && small.top() > large.top()){  // move from small to large
            large.push(small.top());
            small.pop();
        }
        if(small.size() > large.size() + 1){    // move from small to large
            large.push(small.top());
            small.pop();
        }
        if(large.size() > small.size() + 1){    // move from large to small
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size() > large.size()) return small.top();
        else if(large.size() > small.size()) return large.top();
        else return (small.top() + large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */