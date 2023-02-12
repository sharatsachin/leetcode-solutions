// https://leetcode.com/problems/count-the-number-of-fair-pairs

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int l = lower - x;
            int r = upper - x;
            int ibeg = lower_bound(nums.begin(), nums.end(), l) - nums.begin();
            int iend = upper_bound(nums.begin(), nums.end(), r) - nums.begin();
            ans += iend - ibeg - (ibeg <= i && i < iend);
        }
        return ans / 2;
    }
};