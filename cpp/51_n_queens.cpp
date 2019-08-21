#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 8皇后问题，给定n返回所有可能的解。
class Solution {
public:
	bool is_valid(vector<string>& board, int row, int col) {
		// 每一列只能有一个Q
		for (int i = 0; i < row; ++i) {
			if (board[i][col] == 'Q') { return false; }
		}

		// 对角线1
		for (int i = row-1, j = col-1; i >= 0 && j >=0; --i, --j) {
			if (board[i][j] == 'Q') { return false; }
		}

		// 对角线2
		for (int i = row-1, j = col+1; i >= 0 && j < board.size(); --i, ++j) {
			if (board[i][j] == 'Q') { return false; }
		}

		return true;
	}

	void dfs(int row, vector<string>& board, vector<vector<string>>& res) {
		int n = (int)board.size();

		if (n == row) {
			res.push_back(board);
			return;
		}

		for (int i = 0; i < n; ++i) {
			if (is_valid(board, row, i)) {
				board[row][i] = 'Q';
				dfs(row+1, board, res);
				board[row][i] = '.';
			}
		}
	}

    vector<vector<string>> solveNQueens(int n) {
		vector<string> board(n, string(n, '.'));
		vector<vector<string>> res;

		dfs(0, board, res);
		return res;
    }
};
