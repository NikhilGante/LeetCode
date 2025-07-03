class UnionFind:
    
    def __init__(self, n: int):
        self.par = [i for i in range(n)]
        self.rank = [0] * n
        self.size = n 

    def find(self, x: int) -> int:
        if x != self.par[x]:
            self.par[x] = self.find(self.par[x])
        return self.par[x]


    def isSameComponent(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)

    def union(self, x: int, y: int) -> bool:
        p1, p2, = self.find(x), self.find(y)
        if p1 == p2:  # Same component
            return False

        if self.rank[p1] > self.rank[p2]:
            self.par[p2] = p1
        elif self.rank[p2] < self.rank[p2]:
            self.par[p1] = p2
        else:
            self.par[p1] = p2
            self.rank[p2] += 1
        return True

    def getNumComponents(self) -> int:
        num = 0
        for i in range(self.size):
            num += 1 if i == self.par[i] else 0

        return num