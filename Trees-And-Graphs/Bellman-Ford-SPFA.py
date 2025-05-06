import sys
from collections import deque


def bellman_ford_spfa(n, edges, src):
    dist = [sys.maxsize] * n
    dist[src] = 0

    adj_list = [[] for _ in range(n)]

    for edge in edges:
        u, v, w = edge
        adj_list[u].append([v, w])

    queue = deque([])
    queue.append(src)

    visited = [False] * n

    while len(queue) > 0:
        r = queue.popleft()
        visited[r] = False

        for edge in adj_list[r]:
            v, w = edge
            if not visited[v]:
                if dist[r] + w < dist[v]:
                    queue.append(v)
                    dist[v] = dist[r] + w
                    visited[v] = True

    return dist

no = 5
Edges = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]]

Src = 0
ans = bellman_ford_spfa(no, Edges, Src)
print(' '.join(map(str, ans)))
