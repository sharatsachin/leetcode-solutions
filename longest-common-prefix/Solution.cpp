// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& s)
    {
        int ans = s[0].length(), n = size(s), j;
        for (int i = 1; i < n; i++) {
            for(j = 0; j < s[i].length() && s[i][j] == s[0][j]; j++);
            ans = min(ans, j);
        }
        return s[0].substr(0, ans);
    }
};