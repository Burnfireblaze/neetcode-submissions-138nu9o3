class Solution:
    def networkDelayTimeDFS(self, times, n, k):
        adj = collections.defaultdict(list)
        for u, v, w in times:
            adj[u].append((v, w))
        dist = {}

        def dfs(node, t):
            if node in dist and dist[node] <= t:
                return
            dist[node] = t
            for nxt, w in adj[node]:
                dfs(nxt, t + w)

        dfs(k, 0)
        return max(dist.values()) if len(dist) == n else -1

    def networkDelayTimeBellmanFord(self, times, n, k):
        dist = [float("inf")] * (n + 1)
        dist[k] = 0
        for _ in range(n - 1):
            for u, v, w in times:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
        best = max(dist[1:])
        return -1 if best == float("inf") else best

    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        edges = collections.defaultdict(list)
        for u, v, w in times:
            edges[u].append((v, w))

        minHeap = [(0, k)]
        visit = set()
        t = 0
        while minHeap:
            w1, n1 = heapq.heappop(minHeap)
            if n1 in visit:
                continue
            visit.add(n1)
            t = max(t, w1)
            for n2, w2 in edges[n1]:
                if n2 not in visit:
                    heapq.heappush(minHeap, (w1 + w2, n2))
        return t if len(visit) == n else -1
        