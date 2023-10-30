// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> pll;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            int cn = 0, tp = arr[i];
            while(tp > 0) {
                cn += (tp & 1);
                tp >>= 1;
            }
            pll.push_back(make_pair(cn, arr[i]));
        }
        sort(pll.begin(), pll.end());
        vector<int> ret;
        for(int i = 0; i < n; i++) {
            ret.push_back(pll[i].second);
        }
        return ret;
    }
};