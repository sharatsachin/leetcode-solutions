// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {\
        int lmx = -1, rmx = n + 1;
        if (left.size() > 0) lmx = (int) *max_element(left.begin(), left.end());
        if (right.size() > 0) rmx = (int) *min_element(right.begin(), right.end());
        cout << max(lmx, n - rmx);
        return max(lmx, n - rmx);
    }
};