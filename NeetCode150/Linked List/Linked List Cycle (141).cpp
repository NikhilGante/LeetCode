// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode* slow = head, *fast = slow;
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
                if(fast == slow)  return true;
            }
            return false;
        }
    };