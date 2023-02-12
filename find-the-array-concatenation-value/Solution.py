// https://leetcode.com/problems/find-the-array-concatenation-value

class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        sol = 0
        while nums:
            if len(nums) > 1:
                sol += int(str(nums[0]) + str(nums[-1]))
                nums = nums[1:-1]
            else:
                sol += nums[0]
                nums = None
        return sol