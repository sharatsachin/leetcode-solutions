// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] == 2) return true;
        }
        return false;
    }
};