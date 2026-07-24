class Solution {
public:
void bfs(vector<vector<char>>& grid, int r, int c, int rows, int cols){
        queue <pair<int,int>> q;
        q.push({r,c});
        grid[r][c] = '1';
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            if(row+1<rows && grid[row+1][col] == '1'){
                grid[row+1][col] = '#';
                q.push({row+1, col});
            }
            if(row-1>=0 && grid[row-1][col] == '1'){
                grid[row-1][col] = '#';
                q.push({row-1, col});
            }
            if(col+1<cols && grid[row][col+1] == '1'){
                grid[row][col+1] = '#';
                q.push({row, col+1});
            }
            if(col-1>=0 && grid[row][col-1] == '1'){
                grid[row][col-1] = '#';
                q.push({row, col-1});
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), count =0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]=='1'){
                count++;
                bfs(grid, i,j, rows, cols);
                }
            }
        }
        return count;

    }
};
