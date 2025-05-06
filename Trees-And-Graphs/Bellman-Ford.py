import sys


def bellman_ford(n, edges, src):
    dist = [sys.maxsize] * n

    dist[src] = 0

    for i in range(n):
        for edge in edges:
            u, v, w = edge

            if dist[u] + w < dist[v]:

                if i == n:
                    return -1

                dist[v] = dist[u] + w

    return dist


no = 5
Edges = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]]

Src = 0
ans = bellman_ford(no, Edges, Src)
print(' '.join(map(str, ans)))
