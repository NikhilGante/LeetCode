from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        root = ListNode(0)
        cur = root
        carry = 0
        while l1 or l2 or carry:
            val = carry

            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next

            carry, val = divmod(val, 10)        
            cur.next = ListNode(val)
            cur = cur.next
        
        return root.next

# Conversion Approach (convert lists to nums, add them up, and convert back into a list) - less efficient

    # def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    #     def getNumFromLL(l: Optional[ListNode]):
    #         num = 0
    #         i = 1
    #         while l:
    #             num += l.val * i
    #             l = l.next
    #             i *= 10
    #         return num

    #     def numToLL(n: int):
    #         if not n:
    #             return ListNode(0, None)
    #         prev = None
    #         while n:
    #             cur = ListNode(n % 10, None)
    #             if prev:
    #                 prev.next = cur
    #             else:
    #                 root = cur
    #             prev = cur
    #             n //= 10
    #         return root

    #     return numToLL(getNumFromLL(l1) + getNumFromLL(l2))