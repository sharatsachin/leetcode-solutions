// https://leetcode.com/problems/shortest-path-with-alternating-colors

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        vector<vector<vector<int>>> gph(n, vector<vector<int>> (2, vector<int>()));
        for(auto& ed : redEdges) {
            gph[ed[0]][0].push_back(ed[1]);
        }
        for(auto& ed : blueEdges) {
            gph[ed[0]][1].push_back(ed[1]);
        }

        vector<vector<int>> d(n, vector<int>(2, 1e9));
        vector<vector<int>> vis(n, vector<int>(2, 0));
        queue<pair<int, int>> qu;

        vis[0][0] = vis[0][1] = 1;
        qu.push({0, 0});
        qu.push({0, 1});
        d[0][0] = d[0][1] = 0;

        while(!qu.empty()){
            auto [u, f] = qu.front();
            int cd = d[u][f];
            f = 1 - f;
            qu.pop();
            for(auto x: gph[u][f]) {
                if(!vis[x][f]) 
                    vis[x][f] = 1, qu.push({x, f}), d[x][f] = cd + 1;
            }
        } 
        vector<int> ret(n);
        for(int i = 0; i < n; i++) {
            int mn = min(d[i][0], d[i][1]);
            ret[i] = (mn == 1e9 ? -1 : mn);
        }
        return ret;
    }
};