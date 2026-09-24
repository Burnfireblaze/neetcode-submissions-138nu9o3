class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m = len(heights)
        n = len(heights[0])

        pacific = set()
        atlantic = set()

        def dfs(r, c, visited):
            visited.add((r, c))

            directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

            for dr, dc in directions:
                nr = r + dr
                nc = c + dc

                if (
                    0 <= nr < m
                    and 0 <= nc < n
                    and (nr, nc) not in visited
                    and heights[nr][nc] >= heights[r][c]
                ):
                    dfs(nr, nc, visited)

        # Pacific: top row
        for c in range(n):
            dfs(0, c, pacific)

        # Pacific: left column
        for r in range(m):
            dfs(r, 0, pacific)

        # Atlantic: bottom row
        for c in range(n):
            dfs(m - 1, c, atlantic)

        # Atlantic: right column
        for r in range(m):
            dfs(r, n - 1, atlantic)

        # Find cells reachable from both oceans
        result = []

        for r in range(m):
            for c in range(n):
                if (r, c) in pacific and (r, c) in atlantic:
                    result.append([r, c])

        return result