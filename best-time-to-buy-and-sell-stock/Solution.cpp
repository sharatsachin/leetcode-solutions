// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sol = 0;
        int mi = prices[0];
        for(int i = 1; i < n; i++) {
            sol = max(sol, prices[i] - mi);
            mi = min(mi, prices[i]);
        }
        return sol;
    }
};