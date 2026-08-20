class Solution:
    def backtrack(self, n, res, s, open_count, close_count):
        if len(s) == n*2:
            res.append(s)
            return
        if open_count < n:
            self.backtrack(n, res, s + '(', open_count + 1, close_count)
        if close_count < open_count:
            self.backtrack(n, res, s + ')', open_count, close_count+1)

    def generateParenthesis(self, n: int) -> List[str]:
        """
        :type n: int
        :rtype: List[str]
        """
        res = []

        self.backtrack(n, res, "", 0, 0)
        return res
