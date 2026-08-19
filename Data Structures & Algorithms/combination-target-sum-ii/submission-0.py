class Solution:
    def backtracking(self,candidates, target, res, temp, currsum, i):
        if currsum == target:
            res.append(temp[:])
            return
        elif currsum > target or i >= len(candidates):
            return
        temp.append(candidates[i])
        self.backtracking(candidates, target, res, temp, currsum+candidates[i], i+1)
        temp.pop()
        while i+1 < len(candidates) and candidates[i] == candidates[i+1]:
            i += 1
        self.backtracking(candidates, target, res, temp, currsum, i+1)
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        i=0
        res = []
        temp=[]
        candidates.sort()
        self.backtracking(candidates, target, res, temp, 0, i)
        return res