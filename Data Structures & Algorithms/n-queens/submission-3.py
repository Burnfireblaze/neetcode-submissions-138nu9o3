class Solution:

    def solveNQueens(self, n: int) -> List[List[str]]:
        """
        :type n: int
        :rtype: List[List[str]]
        """
        diag1 = set()
        diag2 = set()
        cols = set()
        board = [-1] * n
        res = []

        def build_board():
            row_res=[]
            for row in range(0,n):
                line = ['.']*n
                line[board[row]] = 'Q'
                row_res.append(''.join(line))
            return row_res


        def solve(row):
            if row == n:
                res.append(build_board())
                return

            for col in range(0,n):
                if(col in cols or (row-col) in diag1 or (row + col) in diag2):
                    continue
                
                board[row] = col
                cols.add(col)
                diag1.add(row - col)
                diag2.add(row + col)

                solve(row+1)

                cols.remove(col)
                diag1.remove(row - col)
                diag2.remove(row + col)
        solve(0)
        return res

