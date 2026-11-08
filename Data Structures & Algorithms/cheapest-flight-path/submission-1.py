class Solution:
    def findCheapestPriceBruteForce(self, n, flights, src, dst, k):
        adj = [[] for _ in range(n)]
        for u, v, p in flights:
            adj[u].append((v, p))

        best = [float("inf")]

        def dfs(city, flights_left, cost):
            if city == dst:
                best[0] = min(best[0], cost)
                return
            if flights_left == 0:
                return
            for nxt, price in adj[city]:
                dfs(nxt, flights_left - 1, cost + price)

        dfs(src, k + 1, 0)
        return -1 if best[0] == float("inf") else best[0]

    def findCheapestPriceBellmanFord(self, n, flights, src, dst, k):
        prices = [float("inf")] * n
        prices[src] = 0
        for _ in range(k + 1):
            tmp = prices[:]
            for u, v, p in flights:
                if prices[u] != float("inf") and prices[u] + p < tmp[v]:
                    tmp[v] = prices[u] + p
            prices = tmp
        return -1 if prices[dst] == float("inf") else prices[dst]

    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        """
        :type n: int
        :type flights: List[List[int]]
        :type src: int
        :type dst: int
        :type k: int
        :rtype: int
        """
        adj = [[] for _ in range(n)]
        for u, v, p in flights:
            adj[u].append((v, p))

        heap = [(0, src, 0)]
        best_flights = [float("inf")] * n
        while heap:
            cost, node, used = heapq.heappop(heap)
            if node == dst:
                return cost
            if used == k + 1:
                continue
            if used >= best_flights[node]:
                continue
            best_flights[node] = used
            for nxt, p in adj[node]:
                heapq.heappush(heap, (cost + p, nxt, used + 1))
        return -1