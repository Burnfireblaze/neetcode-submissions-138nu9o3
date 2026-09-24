class Solution {private:
    int m, n;
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;

public:
    void dfs(int r, int c,
             vector<vector<int>>& heights,
             vector<vector<bool>>& visited) {

        visited[r][c] = true;

        int dr[] = {0, -1, 1, 0};
        int dc[] = {-1, 0, 0, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                !visited[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {

                dfs(nr, nc, heights, visited);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n=heights[0].size();
        pacific = vector<vector<bool>>(m, vector<bool>(n, false));
        atlantic = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int c = 0; c < n; c++) {
            dfs(0, c, heights, pacific);
        }

        // Pacific - left
        for (int r = 0; r < m; r++) {
            dfs(r, 0, heights, pacific);
        }

        // Atlantic - bottom
        for (int c = 0; c < n; c++) {
            dfs(m - 1, c, heights, atlantic);
        }

        // Atlantic - right
        for (int r = 0; r < m; r++) {
            dfs(r, n - 1, heights, atlantic);
        }

        vector<vector<int>> res;
        for(int i =0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }

            }
        }
        return res;
    }
};
