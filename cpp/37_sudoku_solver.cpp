#include <iostream>
#include <vector>

using namespace std;

// 让我们解决数独，给9*9的矩形，其中空格用字符`.`，让我们进行填补，假设只要一种情况。
// 暴力搜索即可

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                char c = board[i][j];
                int num = c - '0';
                if (c == '.') {
                    blanks.push_back({i, j});
                } else {
                    setState(i, j, num, 1);
                }
            }
        }
        dfs(0, board);
    }
private:
    struct Value {
        int row;
        int col;
    };
    int col[9][10] = {0};
    int row[9][10] = {0};
    int block[9][10] = {0};
    vector<Value> blanks;

    void setState(int r, int c, int num, int flag) {
        row[r][num] = flag;
        col[c][num] = flag;
        block[blockIndex(r, c)][num] = flag;
    }
    int blockIndex(int row, int col) {
        return row / 3 * 3 + col / 3;
    }
    bool dfs(int idx, vector<vector<char>>& board) {
        if (idx >= blanks.size()) { return true; }
        int row = blanks[idx].row;
        int col = blanks[idx].col;

        for (int i = 1; i <= 9; ++i) {
            if (isValid(row, col, i)) {
                board[row][col] = '0' + i;
                setState(row, col, i, 1);
                if (dfs(idx+1, board)) {
                    return true;
                } else {
                    setState(row, col, i, 0);
                }
            }
        }
        return false;
    }
    bool isValid(int r, int c, int num) {
        return !row[r][num] && !col[c][num] && !block[blockIndex(r, c)][num];
    }
};