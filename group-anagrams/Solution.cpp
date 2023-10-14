// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        int n = strs.size();

        map<string, vector<string>> mp;
        for(int i = 0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (mp.find(s) == mp.end()) {
                mp[s] = vector<string>();
                mp[s].push_back(strs[i]);
            } else {
                mp[s].push_back(strs[i]);
            }
        }
        for (auto& [k, v] : mp) {
            ret.push_back(v);
        }
        return ret;
    }
};