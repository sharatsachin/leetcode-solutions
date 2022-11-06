// https://leetcode.com/problems/convert-1d-array-into-2d-array

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (n * m != original.size()) return vector<vector<int>>();
        vector<vector<int>> ret(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ret[i][j] = original[i * n + j];
            }
        }
        return ret;
    }
};