// https://leetcode.com/problems/greatest-common-divisor-of-strings

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.length();
        int l2 = str2.length();
        bool ret = true;
        int g = gcd(l1, l2);
        for(int i = 0; i < l1; i++) {
            if (str1[i] != str1[i % g]) ret = false; 
        }
        for(int i = 0; i < l2; i++) {
            if (str2[i] != str1[i % g]) ret = false; 
        }
        return ret ? str1.substr(0, g)  : "";
    }
};