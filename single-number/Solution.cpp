// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int sol = 0;
        for(int& x: nums) sol ^= x;
        return sol;
    }
};