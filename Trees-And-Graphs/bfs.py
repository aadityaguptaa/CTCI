from collections import defaultdict

class Graph:

    def __init__(self):
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)
    
    def BFS(self, root):

        visited = [False] * (max(self.graph) + 1)

        queue = []

        queue.append(root)

        visited[root] = True

        while(queue):

            s = queue.pop()
            print(s, end=" ")

            for i in self.graph[s]:
                if(visited[i] == False):
                    queue.append(i)
                    visited[i] = True
        




