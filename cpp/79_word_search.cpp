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

// 给定一个二维矩阵，问能不能一条路径组成的单词就是word
// 回溯即可。也就是遍历二维数组，每个点尝试四个方向上的路径检查。
class Solution {
private:
	vector<pair<int, int>> edges = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
	bool dfs(vector<vector<char>>& board, string word, int x, int y, int idx) {
		int row = board.size(), col = board[0].size();
		if (x < 0 || y < 0 || x >= row || y >= col) { return false; }
		if (board[x][y] != word[idx]) { return false; }
		if (idx == word.size()-1) { return true; }

		char tmp = board[x][y];
		board[x][y] = '$';
		for (auto edge: edges) {
			int x1 = x+edge.first, y1 = y+edge.second;
			if (dfs(board, word, x1, y1, idx+1)) { return true; }
		}
		board[x][y] = tmp;
		return false;
	}

    bool exist(vector<vector<char>>& board, string word) {
		if (board.empty()) { return false; }
		int row = board.size(), col = board[0].size();

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (dfs(board, word, i, j, 0)) { return true; }
			}
		}
		return false;
    }
};
