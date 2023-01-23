// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        map<int, bool> mp;
        vector<int> sol;
        for(int& x: nums) mp[x] = true; 
        for(int i = 1; i <= n; i++) if (!mp[i]) sol.push_back(i);
        return sol;
    }
};