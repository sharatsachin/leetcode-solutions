// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> ve;
        for(auto& [k, v]: mp) {
            ve.push_back({-v, k});
        }
        sort(ve.begin(), ve.end());

        vector<int> ret;
        for(int i = 0; i < k; i++) ret.push_back(ve[i].second);
        return ret;
    }
};