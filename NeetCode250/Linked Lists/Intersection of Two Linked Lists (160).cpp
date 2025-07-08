#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// O(1) Space solution - basically the same as Lowest Common Ancestor of Binary Tree III
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA, *b = headB;
        while(a != b){
            a = a? a->next : headB;
            b = b? b->next : headA;
        }
        return a;
    }
};

// O(n) space solution
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> vis;
        ListNode* cur = headA;
        while(cur){
            vis.insert(cur);
            cur = cur->next;
        }
        cur = headB;
        while(cur){
            if(vis.find(cur) != vis.end()) return cur;
            cur = cur->next;
        }
        return nullptr;
    }
};