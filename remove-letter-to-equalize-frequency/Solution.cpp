// https://leetcode.com/problems/remove-letter-to-equalize-frequency

class Solution {
public:
    bool equalFrequency(string word) {
        map<char, int> mp;
        for(char w : word) mp[w]++;
        for(char c = 'a'; c <= 'z'; c++) {
            mp[c]--;
            
            map<int, int> mp2;
            for(auto& [k, v]: mp) {
                if (v) mp2[v]++;
            }
            if (mp2.size() == 1) return true;
            mp[c]++;
        }
        return false;
    }
};