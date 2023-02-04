// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s2.length() < s1.length())
            return false;
        vector<int> d1(26, 0);
        for (char c : s1)
            d1[c - 'a']++;
        vector<int> d2(26, 0);
        int i = 0, j = 0;

        while (j < s2.length()) {
            d2[s2[j] - 'a']++;
            if (j - i + 1 == s1.length() && d1 == d2)
                    return true;
            if (j - i + 1 < s1.length())
                j++;
            else {
                d2[s2[i] - 'a']--, i++, j++;
            }
        }
        return false;
    }
};