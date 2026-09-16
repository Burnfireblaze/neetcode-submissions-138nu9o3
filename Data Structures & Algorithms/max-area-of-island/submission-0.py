from collections import deque
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        max_val = 0

        nr = [0, -1, 1, 0]
        nc = [-1, 0, 0, 1]

        m = len(grid)
        n = len(grid[0])

        for i in range(0,m):
            for j in range(0,n):
                if grid[i][j] == 1:
                    queue = deque([(i, j)])
                    grid[i][j] = "#"
                    count =0

                    while queue:
                        r,c = queue.popleft()
                        count += 1

                        for k in range(4):
                            dr = r + nr[k]
                            dc = c + nc[k]

                            if (0 <= dr < m and
                                0 <= dc < n and
                                grid[dr][dc] == 1):

                                grid[dr][dc] = "#"
                                queue.append((dr, dc))

                    max_val = max(count, max_val)
        
        return max_val