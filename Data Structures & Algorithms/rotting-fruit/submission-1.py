from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        queue = deque()
        m = len(grid)
        n = len(grid[0])

        nr = [0,-1,1,0]
        nc = [-1,0,0,1]

        fresh = 0
        for i in range(0,m):
            for j in range(0,n):
                if grid[i][j] == 2:
                    queue.append((i,j))
                elif grid[i][j] == 1:
                    fresh += 1
        count = 0
        while queue and fresh:
            for _ in range(len(queue)):
                r, c = queue.popleft()
                for i in range(0,4):
                    dr = r + nr[i]
                    dc = c + nc[i]
                    if dr >= 0 and dr < m and dc >= 0 and dc < n and grid[dr][dc] == 1:
                        grid[dr][dc] = grid[r][c] + 1
                        queue.append((dr,dc))
                        fresh -= 1
            count = count + 1
        return count if fresh == 0 else -1