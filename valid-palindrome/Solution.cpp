// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(char i : s) {
            if ((i >= 'a' && i <= 'z')||(i >= 'A' && i <= 'Z' )||(i >= '0' && i <= '9' )) t += tolower(i);
        }
        int n = t.length();
        for(int i = 0; i < (int) n/2; i++) {
            if (t[i] != t[n-i-1]) return false;
        }
        return true;
    }
};