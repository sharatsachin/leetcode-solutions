// https://leetcode.com/problems/add-to-array-form-of-integer

class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        ans, i = [], len(A) - 1
        while K > 0 or i >= 0:
            K, rmd = divmod(K + (A[i] if i >= 0 else 0), 10)
            ans.append(rmd)
            i -= 1
        return reversed(ans)