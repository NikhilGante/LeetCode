/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
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