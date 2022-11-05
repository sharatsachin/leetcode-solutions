// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);

            int p = mp[nums[i]].size();
            if (p > 1) {
                if (mp[nums[i]][p-1] - mp[nums[i]][p-2] <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};