#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct compare{
    bool operator() (ListNode*& a, ListNode*& b){
        return a->val > b->val;
    }
};

class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<ListNode*, vector<ListNode*>, compare> pq;
            for(auto& l: lists) if(l) pq.push(l);

            ListNode dummy = ListNode(), *prev = &dummy;
            while(!pq.empty()){
                ListNode* cur = pq.top();
                pq.pop();
                prev->next = cur;
                prev = cur;

                if(cur->next)   pq.push(cur->next);
            }
            return dummy.next;   
        }
};