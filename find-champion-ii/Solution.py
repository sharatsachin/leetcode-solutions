// https://leetcode.com/problems/find-champion-ii

class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        all = list(range(n))
        for i in range(len(edges)):
            if edges[i][1] in all:
                all.remove(edges[i][1])
        if len(all) == 1:
            return all[0]
        else:
            return -1