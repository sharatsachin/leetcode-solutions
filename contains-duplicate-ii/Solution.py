// https://leetcode.com/problems/contains-duplicate-ii

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        map = dict()
        for i, el in enumerate(nums):
            if el in map.keys():
                if i - map[el] <= k:
                    return True
            map[el] = i
        return False