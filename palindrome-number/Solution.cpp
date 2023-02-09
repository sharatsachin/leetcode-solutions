// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return 0;
        long long a = x, b = 0;
        while(x)  b = b * 10 + (x % 10), x /= 10;
        return b == a;
    }
};