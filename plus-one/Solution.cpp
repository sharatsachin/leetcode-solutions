// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int all_9 = true;
        for(int i = 0; i < n; i++) {
            if (digits[i] != 9) all_9 = false;
        }
        vector<int> ret(n + (int)all_9);
        if (all_9) {
            ret[0] = 1;
            return ret;
        } else {
            ret.assign(digits.begin(), digits.end());
            for(int i = n-1; i>=0; i--) {
                if (ret[i] == 9) {
                    ret[i] = 0;
                    continue;
                } else {
                    ret[i]++;
                    break;
                }
            }
        }
        return ret;
    }
};