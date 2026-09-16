class Solution:
    def dfs(self, i, j, grid, m, n):
        grid[i][j] = "#"
        nr = [0, -1, 1, 0]
        nc = [-1, 0, 0, 1]
        for k in range(4):
            dr, dc = i + nr[k], j + nc[k]
            if 0 <= dr < m and 0 <= dc < n and grid[dr][dc] == "1":
                self.dfs(dr, dc, grid, m, n)
        
        
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        count = 0
        for i in range(0,m):
            for j in range(0,n):
                if grid[i][j] == "1":
                    self.dfs(i, j, grid, m, n)
                    count += 1
        return count