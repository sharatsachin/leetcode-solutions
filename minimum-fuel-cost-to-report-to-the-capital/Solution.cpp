// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital

class Solution {
public:
    long long minimumFuelCost(vector<vector<int> >& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int> > adj(n);
        for (auto& r : roads) {
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }
        vector<int> sz(n, 1);
        function<void(int, int)> dfs = [&](int u, int p) {
            for (int v : adj[u]) {
                if (v != p) {
                    dfs(v, u);
                    sz[u] += sz[v];
                }
            }
        };
        dfs(0, -1);
        return accumulate(
            sz.begin() + 1, sz.end(), 0ll,
            [seats](long long lhs, int rhs) { return lhs + (rhs + seats - 1) / seats; });
    }
};