// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.length() - 1, j = b.length() - 1, ca = 0;
        while(i >= 0 || j >= 0){
            int sum = ca;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            ca = sum > 1 ? 1 : 0;
            res.push_back(sum % 2 + '0');
        }
        if(ca) res.push_back(ca + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};