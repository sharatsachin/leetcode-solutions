// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        double l, r, m;
        l = 1, r = x;
        m = (l+r) / 2;

        while (abs(l - r) > 1e-9) {
            m = (l+r) / 2;
            if (m * m > x) {
                r = m - 1e-9;
            } else if (m * m < x) {
                l = m + 1e-9;
            }
        }
        m += 1e-6;
        cout << m << '\n';
        return (int) m;
    }
};