// https://leetcode.com/problems/substring-xor-queries

class Solution {
public:
    vector<vector<int> > substringXorQueries(string s, vector<vector<int> >& qu)
    {
        int n = s.size(), q = qu.size();
        vector<vector<int> > ans;
        unordered_map<long long, vector<int> > mp;
        mp[-1] = { -1, -1 };
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (!mp.count(0))
                    mp[0] = { i, i };
                continue;
            }
            long long num = 0;
            for (int j = i; j <= min(i + 32, n - 1); j++) {
                num = (num << 1) + (s[j] - '0');
                if (!mp.count(num))
                    mp[num] = { i, j };
            }
        }
        int x = 0;
        for (int i = 0; i < q; i++)
            x = qu[i][0] ^ qu[i][1], ans.push_back(mp.count(x) ? mp[x] : mp[-1]);
        return ans;
    }
};