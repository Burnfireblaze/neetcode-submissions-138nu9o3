class Solution:
    def check_palindrome(self, s, left, right):
        while left < right:
            if s[left] != s[right]:
                return False
            left+=1
            right-=1
        return True
    def backtrack(self, s,res, part, i):
        if i >= len(s):
            res.append(part[:])   # ← record! you fell off the end successfully
            return
    
        for j in range(i,len(s)):
            chunk = s[i:j+1]
            if self.check_palindrome(s, i,j):
                part.append(chunk)          # pick this chunk
                self.backtrack(s, res, part, j+1)   # continue from j
                part.pop()                  # undo

    def partition(self, s: str) -> List[List[str]]:
        """
        :type s: str
        :rtype: List[List[str]]
        """
        res  = []
        self.backtrack(s,res,[], 0)
        return res