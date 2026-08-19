class Solution:
    def backtracking(self, nums, res, temp, i):
        if i == len(nums):
            res.append(temp[:])
            return

        temp.append(nums[i])
        self.backtracking(nums,res, temp, i+1)

        temp.pop()
        self.backtracking(nums,res, temp, i+1)

    def subsets(self, nums: List[int]) -> List[List[int]]:
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        temp = []

        self.backtracking(nums, res, temp, 0)

        return res