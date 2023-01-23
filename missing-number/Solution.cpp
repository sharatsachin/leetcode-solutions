// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        map<int, bool> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = true;
        }
        for(int i = 0; i <= n; i++) {
            if (!mp[i]) return i;
        }
        return -1;
    }
};