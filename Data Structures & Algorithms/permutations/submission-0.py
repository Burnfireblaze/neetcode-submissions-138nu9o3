class Solution:
    def backtracking(self, nums, res, temp, i):
        if len(temp) == len(nums):
            res.append(temp[:])
            return

        for num in nums:
            if num not in temp:
                temp.append(num)
                self.backtracking(nums,res, temp, i+1)
                temp.pop()

        
    def permute(self, nums: List[int]) -> List[List[int]]:
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        temp = []

        self.backtracking(nums, res, temp, 0)

        return res