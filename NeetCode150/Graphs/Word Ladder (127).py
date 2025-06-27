from typing import List
from collections import defaultdict
from collections import deque

# Initial solution
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordList.append(beginWord)
        wordSet = set(wordList)
        wordList = list(wordSet)
        adj = defaultdict(list) # Maps str to list of strs

        def differsByOne(a: str, b: str) -> bool:
            offCount = 0
            for i in range(len(a)):
                if a[i] != b[i]:
                    offCount += 1
                    if offCount > 1:
                        return False
            return offCount == 1

        for a in wordList:
            wordSet.remove(a)
            for b in wordSet:
                if differsByOne(a, b):
                    adj[a].append(b)
                    adj[b].append(a)

        visited = set()

        q = deque([(beginWord, 1)])
        while q:
            for _ in range(len(q)):
                node, depth = q.popleft()
                if node == endWord:
                    return depth

                visited.add(node)

                for nei in adj[node]:
                    if nei not in visited:
                        q.append((nei, depth + 1))

        return 0
