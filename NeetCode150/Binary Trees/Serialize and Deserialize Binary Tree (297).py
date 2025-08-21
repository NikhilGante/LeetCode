from collections import deque

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import sys
input = sys.stdin.readline

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return ""

        q = deque()
        q.append(root)
        lst = [str(root.val)]
        while q:
            size = len(q)
            cur = q.popleft()
            if cur.left:
                q.append(cur.left)
                lst.append(str(cur.left.val))
            else:
                lst.append('')
            if cur.right:
                q.append(cur.right)
                lst.append(str(cur.right.val))
            else:
                lst.append('')

        ans = ','.join(lst)
        return ans
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        arr = data.split(',')
        if(arr[0] == ''):
            return None

        q = deque()
        root = TreeNode(arr[0])
        q.append(root)
        i = 1
        while q:
            cur = q.popleft()
            if arr[i] != '':
                cur.left = TreeNode(arr[i])
                q.append(cur.left)
            i += 1
            if arr[i] != '':
                cur.right = TreeNode(arr[i])
                q.append(cur.right)
            i += 1

        return root

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))