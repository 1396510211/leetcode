#include "../pch.h"


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool r[9][9], c[9][9], s[3][3][9];
        memset(r, false, 9 * 9);
        memset(c, false, 9 * 9);
        memset(s, false, 3 * 3 * 9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (!isdigit(board[i][j]))
                    continue;
                int num = ch - '1';
                // 如果在第i行已经出现过了
                if (r[i][num] == true)
                    return false;
                r[i][num] = true;
                // 如果在第j列已经出现过了
                if (c[j][num] == true) 
                    return false;
                c[j][num] = true;
                int ii = i / 3;
                int jj = j / 3;
                // 如果在九宫格已经出现过了
                if (s[ii][jj][num] = true)
                    return false;
                s[ii][jj][num] = true;
            }
        }
        return true;
    }
};