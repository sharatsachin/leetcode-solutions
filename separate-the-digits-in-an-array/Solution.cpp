// https://leetcode.com/problems/separate-the-digits-in-an-array

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ret;
        for(auto& x : nums) {
            int a = x;
            vector<int> ret1;
            while(a) {
                ret1.push_back(a % 10);
                a /= 10;
            }
            for(auto it = ret1.rbegin(); it != ret1.rend(); ++it) {
                ret.push_back(*it);
            }
        }
        return ret;
    }
};