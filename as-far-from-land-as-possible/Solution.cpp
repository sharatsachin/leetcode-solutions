// https://leetcode.com/problems/as-far-from-land-as-possible

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> v1, v0;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            (grid[i][j] ? v1 : v0).push_back({i, j});
        }
        if (v1.size() == 0 or v0.size() == 0) return -1;
        int ret = 0;
        for(auto& [a, b] : v0) {
            int mn = 1e3;
            for(auto& [x, y] : v1) {
                mn = min(mn, abs(a-x) + abs(b-y));
                // cout << a << ',' << x << ',' << b << ',' << y << ',' << abs(a-x) + abs(b-y) << '\n';
            }
            ret = max(ret, mn);
        }
        return ret;
    }
};