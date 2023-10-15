// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> rets;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                auto it = next(nums.begin(), j+1);
                if (binary_search(it, nums.end(), -(nums[i] + nums[j]))) {
                    rets.insert(
                        {nums[i], nums[j], -(nums[i] + nums[j])}
                    );
                }
            }
        }
        vector<vector<int>> retv(rets.begin(), rets.end());
        return retv;
    }
};