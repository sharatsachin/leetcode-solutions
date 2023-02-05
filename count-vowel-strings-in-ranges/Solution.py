// https://leetcode.com/problems/count-vowel-strings-in-ranges

class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        is_it = [int(x[0] in ["a","e","i","o","u"] and x[-1] in ["a","e","i","o","u"]) for x in words]
        is_it_sum = [0 for _ in range(len(is_it) + 1)]
        
        for i in range(len(is_it)):
            is_it_sum[i + 1] = is_it_sum[i] + is_it[i]
        
        return [is_it_sum[b+1] - is_it_sum[a] for a, b in queries]