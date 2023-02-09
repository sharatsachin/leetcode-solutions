// https://leetcode.com/problems/naming-a-company

//Optimized code - O(n*m) and O(26*n) space
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long disName = 0;
        vector<unordered_set<string>> v(26);
        for (string s : ideas) 
            v[s[0] - 'a'].insert(s.substr(1));
        
        for (int i = 0; i < 25; i++) {
            for (int j = i + 1; j < 26; j++) {
                unordered_set<string> st;
                st.insert(v[i].begin(), v[i].end());
                st.insert(v[j].begin(), v[j].end());
                disName += 2 * (v[i].size() - st.size()) * (v[j].size() - st.size());
            }
        }
        return disName;
    }
};