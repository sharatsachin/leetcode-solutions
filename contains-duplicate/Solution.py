// https://leetcode.com/problems/contains-duplicate

from collections import Counter

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        cnts = Counter(nums)
        for x, y in cnts.items():
            if y > 1:
                return True
        return False