// https://leetcode.com/problems/contains-duplicate-iii

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        deque<int> cand;
        int n = nums.size(), ge_i, le_i;
        // cout << "FUNC\n";
        for(int i = 0; i < n; i++) {
            ge_i = distance(cand.begin(), lower_bound(cand.begin(), cand.end(), nums[i]));
            le_i = distance(cand.begin(), upper_bound(cand.begin(), cand.end(), nums[i])) - 1;
            // cout << i << ' ' << ge_i << ' ' << le_i << '\n';
            
            if (ge_i != cand.size() && cand[ge_i] - nums[i] <= valueDiff) return true;
            if (le_i != -1  && nums[i] - cand[le_i] <= valueDiff) return true;
            // for(auto x : cand) cout << x << ' '; cout << '\n';
            
            cand.insert(ge_i + cand.begin(), 1, nums[i]);
            if (cand.size() > indexDiff) {
                auto to_rem = lower_bound(cand.begin(), cand.end(), nums[i - indexDiff]);
                cand.erase(to_rem);
            }
            // for(auto x : cand) cout << x << ' '; cout << '\n';
        }
        return false;
    }
};