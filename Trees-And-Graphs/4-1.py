from collections import defaultdict

class Graph:
    def __init__(self):
        self.dic = defaultdict(list)

    def addEdge(self, u, v):
        self.dic[u].append(v)

    def ifPathExists(self, u, v):

        visited = [False] * (max(self.dic) + 1)

        queue = []
        queue.append(u)
        visited[u] = True

        while queue:

            s = queue.pop()
            if(s == v):
                return True
            
            for i in self.dic[s]:
                if( visited[i] != True ):
                    queue.append(i)
                    visited[i] = True
                    

        return False
    
g = Graph()
g.addEdge(0, 1)
g.addEdge(2, 3)
g.addEdge(3, 3)


print(g.ifPathExists(2, 3))

