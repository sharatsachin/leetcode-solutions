// https://leetcode.com/problems/convert-1d-array-into-2d-array

class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if m * n != len(original):
            return []
        ret = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                ret[i][j] = original[i * n + j]
        return ret