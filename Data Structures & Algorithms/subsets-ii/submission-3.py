class Solution:
    def backtracking(self, nums, res, temp, i):
        if i == len(nums):
            res.append(temp[:])
            return
        elif i> len(nums):
            return

        temp.append(nums[i])
        self.backtracking(nums,res, temp, i+1)
        temp.pop()
        while(i+1<len(nums) and nums[i]==nums[i+1]):
            i= i+1
        self.backtracking(nums,res, temp, i+1)
        
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        temp = []

        nums.sort()

        self.backtracking(nums, res, temp, 0)

        return res