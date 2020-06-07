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

// 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

// dfs;
class Solution {
private:
	vector<pair<int, int>> edges = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
	bool dfs(vector<vector<char>>& board, string word, int x, int y, int idx) {
		int row = board.size(), col = board[0].size();
		if (x < 0 || y < 0 || x >= row || y >= col) { return false; }
		if (board[x][y] != word[idx]) { return false; }
		if (idx == word.size()-1) { return true; }

		int tmp = board[x][y];
		board[x][y] = '$';
		for (auto edge: edges) {
			int x1 = x+edge.first, y1 = y+edge.second;
			if (dfs(board, word, x1, y1, idx+1)) { return true; }	
		}
		board[x][y] = tmp;
		return false;
	}

    bool exist(vector<vector<char>>& board, string word) {
		int row = board.size();
		if (row == 0) { return false; }
		int col = board[0].size();
		if (col == 0) { return false; }

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (dfs(board, word, i, j, 0)) { return true; }
			}
		}

		return false;
    }
};
