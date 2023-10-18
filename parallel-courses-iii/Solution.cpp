// https://leetcode.com/problems/parallel-courses-iii

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& t) {
        vector<vector<int>> g(n + 1);
        vector<int> in(n + 1, 0);
        
        for (const auto& r : rel) {
            g[r[0]].push_back(r[1]);
            in[r[1]]++;
        }
        
        queue<int> q;
        vector<int> s(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                q.push(i);
                s[i] = 0;
            }
        }
        
        int m = 0;
        
        while (!q.empty()) {
            int c = q.front();
            q.pop();
            
            m = max(m, s[c] + t[c - 1]);
            
            for (int nc : g[c]) {
                in[nc]--;
                s[nc] = max(s[nc], s[c] + t[c - 1]);
                
                if (in[nc] == 0) {
                    q.push(nc);
                }
            }
        }
        
        return m;
    }
};
