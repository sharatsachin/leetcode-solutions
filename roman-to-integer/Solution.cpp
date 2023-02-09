// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s)
    {
        map<char, int> mp = {
            { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 }
        };
        int ret = 0;
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] < mp[s[i + 1]])
                ret = ret - mp[s[i]];
            else
                ret = ret + mp[s[i]];
        }
        return ret;
    }
};