// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = size(nums);
        int mx = 0;
        for(int i = 0; i < n - 1; i++) {
            if (i <= mx) mx = max(mx, i + nums[i]);
            else return false;
        }
        return mx >= n - 1;
    }
};