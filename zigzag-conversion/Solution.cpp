// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    int valid(int r, int c, vector < vector < char >> & mat) {
        if (r >= 0 && r < mat.size()) {
            if (mat[r][c] == ' ') return 1;
            else return 0;
        }
        return -1;
    }
    string convert(string s, int numRows) {
        int n = s.length();
        if (numRows == 1) return s;
        int nc = n;
        vector < vector < char >> mat(numRows, vector < char > (n, ' '));

        int r = 0, c = 0;
        for (int i = 0; i < n; i++) {
            mat[r][c] = s[i];
            if (valid(r - 1, c, mat) < 1 && valid(r + 1, c, mat) == 1) {
                r += 1;
            } else {
                r -= 1;
                c += 1;
            }
        }

        string sol;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != ' ') {
                    sol += mat[i][j];
                }
            }
        }
        return sol;
    }
};