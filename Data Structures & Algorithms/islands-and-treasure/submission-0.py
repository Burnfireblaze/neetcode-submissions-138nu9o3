from collections import deque
class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        queue = deque()
        m = len(grid)
        n = len(grid[0])

        nr = [0,-1,1,0]
        nc = [-1,0,0,1]


        for i in range(0,m):
            for j in range(0,n):
                if grid[i][j] == 0:
                    queue.append((i,j))
        
        while queue:
            r,c = queue.popleft()
            for i in range(0,4):
                dr = r + nr[i]
                dc = c + nc[i]

                if dr >= 0 and dr < m and dc >= 0 and dc < n and grid[dr][dc] == 2147483647:
                    grid[dr][dc] = grid[r][c] + 1
                    queue.append((dr,dc))

        