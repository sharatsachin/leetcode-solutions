// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_map<int, std::pair<int, int>> mp;
        std::unordered_map<int, bool> bl;
        int mx = 0;
        
        for (int i : nums) {
            if (bl[i]) {
                continue;
            }
            bl[i] = true;
            int l = i, r = i;
            
            if (mp.find(i + 1) != mp.end()) {
                r = mp[i + 1].first;
            }
            if (mp.find(i - 1) != mp.end()) {
                l = mp[i - 1].second;
            }
            mp[r] = std::make_pair(r, l);
            mp[l] = std::make_pair(r, l);
            mx = std::max(mx, r - l + 1);
        }
        
        return mx;
    }
};