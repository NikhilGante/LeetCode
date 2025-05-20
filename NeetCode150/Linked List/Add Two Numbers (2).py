from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        def getNumFromLL(l: Optional[ListNode]):
            num = 0
            i = 1
            while l:
                num += l.val * i
                l = l.next
                i *= 10
            return num

        def numToLL(n: int):
            if not n:
                return ListNode(0, None)
            prev = None
            while n:
                cur = ListNode(n % 10, None)
                if prev:
                    prev.next = cur
                else:
                    root = cur
                prev = cur
                n //= 10
            return root

        return numToLL(getNumFromLL(l1) + getNumFromLL(l2))