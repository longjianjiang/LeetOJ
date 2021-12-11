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

class Solution {
private:
	vector<pair<int, int>> edges = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
	bool dfs(int idx, vector<vector<char>>& board, string word, int x, int y, int rows, int cols) {
		if (x < 0 || y < 0 || x >= rows || y >= cols) { return false; }
		if (board[x][y] != word[idx]) { return false; }
		if (idx == word.size()-1) { return true; }

		char tmp = board[x][y];
		board[x][y] = '$';
		for (auto edge: edges) {
			int x2 = x + edge.first, y2 = y + edge.second;
			if (dfs(idx+1, board, word, x2, y2, rows, cols)) { return true; }
		}
		board[x][y] = tmp;
		return false;
	}

    bool exist(vector<vector<char>>& board, string word) {
		int rows = board.size();
		if (rows == 0) { return false; }
		int cols = board[0].size();
		if (cols == 0) { return false; }

		for (int x = 0; x < rows; ++x) {
			for (int y = 0; y < cols; ++y) {
				bool res = dfs(0, board, word, x, y, rows, cols);
				if (res) { return res; }
			}
		}

		return false;
    }
};

