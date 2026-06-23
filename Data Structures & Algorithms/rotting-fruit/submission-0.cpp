class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        queue <pair<int,int>> q;
        int fresh = 0;

        for(int i =0; i<m;i++)
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        
        if (fresh == 0) return 0;

        int dr[]={-1, 1, 0, 0}, dc[]={0, 0, -1, 1 };
        int count=-1;

        while(!q.empty()){
            int size = q.size();
            count++;
            for(int i=0; i<size; i++) {
                auto [r,c] = q.front(); q.pop();
                for(int k=0; k<4; k++){
                    int nc = dc[k] + c, nr = dr[k] + r;
                    if (nr<0||nr>=m||nc<0||nc>=n||grid[nr][nc]!=1) continue;
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr,nc});
                }
            }
        }
        return fresh == 0 ? count : -1;
    }
};
