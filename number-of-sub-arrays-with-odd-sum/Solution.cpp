// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum

const int mod = 1e9 + 7;

class Solution {
public:
    int numOfSubarrays(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(2, vector<int> (n+1, 0));
        for(int i = 1; i <= n; i++)
        {
            int x = a[i-1] % 2;
            dp[x][i] = 1 + dp[0][i-1];
            dp[1-x][i] = dp[1][i-1];
        }
        return accumulate(dp[1].begin(), dp[1].end(), 0ll, [](int l, int r){return (l + r) % mod;});   
    }
};