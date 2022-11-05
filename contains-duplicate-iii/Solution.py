// https://leetcode.com/problems/contains-duplicate-iii

class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        n = len(nums)
        st = []
        for i, el in enumerate(nums):
            ge = bisect_left(st, el)
            le = bisect_right(st, el) - 1
            if ge != len(st) and st[ge] - el <= valueDiff:
                return True
            if le != -1 and el - st[le] <= valueDiff:
                return True
            insort_left(st, el)
            if len(st) > indexDiff:
                st.remove(nums[i - indexDiff])
        return False