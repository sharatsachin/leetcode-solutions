// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i < n - m + 1; ++i) {
            int j;
            for (j = 0; j < m; ++j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == m) return i;
        }
        return -1;
    }
};