from typing import List

class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        adj = [0] * 26
        for w in words:
            for c in w:
                i = ord(c) - ord('a')
                if not adj[i]:
                    adj[i] = set()
        for w in range(len(words) - 1, 0, -1):
            w1, w2 = words[w], words[w - 1]
            minLen = min(len(w1), len(w2))
            if len(w2) > len(w1) and w1[:minLen] == w2[:minLen]:
                return ''
            for c in range(minLen):
                a, b = ord(w1[c]) - ord('a'), ord(w2[c]) - ord('a')
                if a != b: # Can't have node point to itself
                    adj[a].add(b)
                    break

        vis = [False] * 26
        path = [False] * 26
        ans = []
        def dfs(node: int) -> bool:
            if path[node]:
                return False
            if vis[node]:
                return True
            
            path[node] = True
            vis[node] = True

            if adj[node]:
                for nei in adj[node]:
                    if not dfs(nei):
                        return False
                
            path[node] = False  # Unmark
            ans.append(chr(node + ord('a')))
            return True
            
        for i in range(26):
            if adj[i] != 0:
                if not dfs(i):
                    return ''
        
        return ''.join(ans)
    