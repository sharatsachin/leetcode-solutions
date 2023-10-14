// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {
            int n = 0;
            set<char> st;
            for(int j = 0; j < 9; j++) {
                if (board[i][j] != '.') st.insert(board[i][j]), n++;
            }
            if (n != st.size()) return false;
        }
        
        for(int j = 0; j < 9; j++) {
            int n = 0;
            set<char> st;
            for(int i = 0; i < 9; i++) {
                if (board[i][j] != '.') st.insert(board[i][j]), n++;
            }
            if (n != st.size()) return false;
        }

        for(int m = 0; m < 9; m += 3) {
            for(char p = 0; p < 9; p += 3) {
                int n = 0;
                set<int> st;
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        if (board[m+i][p+j] != '.') st.insert(board[m+i][p+j]), n++;
                    }
                }
                if (n != st.size()) return false;
            }
        }

        return true;
    }
};