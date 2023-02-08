// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = size(nums);
        vector<int> dp(n, 1e9);
        dp[0] = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j <= nums[i] && i + j < n; j++) {
                dp[i+j] = min(dp[i+j], dp[i] + 1);
            }
        }
        return dp[n-1];
    }
};