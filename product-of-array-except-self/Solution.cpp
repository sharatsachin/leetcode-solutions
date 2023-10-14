// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<long long> lsum(n, 1), rsum(n, 1); 
        for(int i = 1; i < n; i++) {
            lsum[i] = lsum[i-1] * nums[i-1];
        }
        for(int i = n - 2; i >= 0; i--) {
            rsum[i] = rsum[i+1] * nums[i+1];
        }
        vector<int> ret(n, 1);
        // for(int i = 0; i < n; i++) {
        //     cout << lsum[i] << " ";
        // }
        // cout << '\n';
        // for(int i = 0; i < n; i++) {
        //     cout << rsum[i] << " ";
        // }
        // cout << '\n';
        for(int i = 0; i < n; i++) {
            ret[i] = lsum[i] * rsum[i];
        }
        return ret;
    }
};