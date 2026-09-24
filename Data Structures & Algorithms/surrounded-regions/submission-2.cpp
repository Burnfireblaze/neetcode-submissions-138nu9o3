class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, int m, int n){
        int dr[] = {-1,0,0,1};
        int dc[] = {0,-1,1,0};
        int safe = false;
        
        for(int k=0; k<4;k++){
            int nr = dr[k] + i;
            int nc = dc[k] + j;
            if(nr>=0 && nr<m-1 && nc>=0 && nc<n-1 && board[nr][nc] == 'O' ){
                board[nr][nc] = 'S';
                dfs(nr, nc, board, m, n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int c = 0; c < n; c++) {
            if(board[0][c] == 'O'){
                board[0][c] = 'S';
                dfs(0, c, board, m, n);
            }
        }

        // Pacific - left
        for (int r = 0; r < m; r++) {
            if(board[r][0] == 'O'){
                board[r][0] = 'S';
                dfs(r, 0, board, m, n);
            }
        }

        // Atlantic - bottom
        for (int c = 0; c < n; c++) {
            if(board[m-1][c] == 'O'){
                board[m-1][c] = 'S';
                dfs(m - 1, c, board, m, n);
            }
        }

        // Atlantic - right
        for (int r = 0; r < m; r++) {
            if(board[r][n-1] == 'O'){
            board[r][n-1] = 'S';
            dfs(r, n - 1, board, m, n);
            }
        }

        vector<vector<int>> res;
        for(int i =0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'S'){
                    board[i][j] = 'O';
                }

            }
        }
    }
};
