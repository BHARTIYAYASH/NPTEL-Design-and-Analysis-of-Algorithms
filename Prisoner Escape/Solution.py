import sys
from collections import deque

def main():
    input = sys.stdin.read().split()
    idx = 0
    L = int(input[idx]); idx += 1
    W = int(input[idx]); idx += 1
    N = int(input[idx]); idx += 1

    soldiers = []
    for _ in range(N):
        x = int(input[idx]); idx += 1
        y = int(input[idx]); idx += 1
        soldiers.append((x, y))

    adj = [[] for _ in range(N + 2)]
    s = N
    t = N + 1

    for i in range(N):
        x, y = soldiers[i]
        if y <= 100:
            adj[i].append(s)
            adj[s].append(i)
        if (W - y) <= 100:
            adj[i].append(t)
            adj[t].append(i)

    for i in range(N):
        x1, y1 = soldiers[i]
        for j in range(i + 1, N):
            x2, y2 = soldiers[j]
            dx = x1 - x2
            dy = y1 - y2
            dist_sq = dx * dx + dy * dy
            if dist_sq <= 200 * 200:
                adj[i].append(j)
                adj[j].append(i)

    visited = [False] * (N + 2)
    q = deque()
    q.append(s)
    visited[s] = True
    found = False

    while q:
        u = q.popleft()
        if u == t:
            found = True
            break
        for v in adj[u]:
            if not visited[v]:
                visited[v] = True
                q.append(v)

    print(1 if found else 0)

if __name__ == "__main__":
    main()