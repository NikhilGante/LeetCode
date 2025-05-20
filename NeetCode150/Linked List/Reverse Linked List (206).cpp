// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
    
            
        // Naive Solution (Create new list)
        /*
        ListNode* reverseList(ListNode* head) {
            ListNode* read_node = head, *prev = nullptr, *cur = nullptr;
            while(read_node){
                cur = new ListNode(read_node->val, prev);
                prev = cur;
                read_node = read_node->next;
            }
            return cur;
        }
        */
};