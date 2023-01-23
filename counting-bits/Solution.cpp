// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> solList;
        for(int i = 0; i <= n; i++) {
            int sol = 0;
            int p = i;
            while (p > 0) {
                sol += p & 1;
                p >>= 1;
            }
            solList.push_back(sol);
        }
        return solList;
    }
};