// https://leetcode.com/problems/find-closest-node-to-given-two-nodes

class Solution {
public:
    vector<pair<int, int>> nextNodes(vector<int>& edges, int k, int N)  {
        int i = 0;
        vector<pair<int, int>> ret;
        vector<int> vis(N);
        
        ret.push_back({i, k});
        vis[k] = 1;
        
        while (edges[k] != -1 && !vis[edges[k]]) {
            ret.push_back({i + 1, edges[k]});
            vis[edges[k]] = 1;
            i += 1;
            k  = edges[k];
        }
        return ret;
    } 

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int N = edges.size();
        auto a1 = nextNodes(edges, node1, N);
        auto a2 = nextNodes(edges, node2, N);
        map<int, int> mp;
        for(auto &[x, y] : a1) {
            mp[y] = x;
        }
        int mn = 1e6, mn_i = -1;

        for(auto &[x, y] : a2) {
            if (mp.find(y) != mp.end()) {
                mp[y] = max(x, mp[y]);
                cout << x << ',' << y << " "; 
                cout << "\n";
                if ((mp[y] < mn) || (mp[y] <= mn && y < mn_i)) {
                    mn = mp[y];
                    mn_i  = y; 
                }
            }
        }
        return mn_i;
    }
};