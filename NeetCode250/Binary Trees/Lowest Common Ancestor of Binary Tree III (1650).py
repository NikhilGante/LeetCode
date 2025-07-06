
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None


"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""
# Optimal Solution - O(logn) time, O(1) space
class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        a, b = p, q
        while a != b:
            a = a.parent if a else q    # Switch over to other node once reaching top
            b = b.parent if b else p
        return a

# Initial Solution O(n) time, O(1) space
class Solution2:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        root = p
        while root.parent:
            root = root.parent
        def dfs(node): # (node, hasp, hasq)
            if not node:
                return (None, False, False)
            hasp, hasq = node.val == p.val, node.val == q.val
            res1 = dfs(node.left)
            res2 = dfs(node.right)

            if res1[0]:
                return res1
            if res2[0]:
                return res2

            hasp |= res1[1] | res2[1]
            hasq |= res1[2] | res2[2]
            ret = node if hasp and hasq else None
            return (ret, hasp, hasq)

        return dfs(root)[0]

