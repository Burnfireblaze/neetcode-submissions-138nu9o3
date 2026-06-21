class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;

        vector <vector <int>> dist(n, vector<int>(n,-1));
        queue <pair<int, int>> q;

        q.push({0,0});
        dist[0][0] = 1;

        int dr[8]={-1,-1,-1,0,0,1, 1,1};
        int dc[8]={-1,0, 1,-1,1,-1,0,1};

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            if(row==n-1 && col == n-1)
            return dist[row][col];
            
            for(int i =0; i<8;i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nc<0 || nr<0 || nr >= n || nc >= n || grid[nr][nc] == 1 || dist[nr][nc] != -1)
                continue;

                dist[nr][nc] = dist[row][col] + 1;

                q.push({nr,nc}); 
            }
        }
        return -1;
    }
};