class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        prev2 = nums[0]
        prev1 = max(nums[1],nums[0])
        
        
        for i in range(2,len(nums)):
            curr = max(nums[i]+prev2, prev1)
            prev2 = prev1
            prev1 = curr
        return prev1