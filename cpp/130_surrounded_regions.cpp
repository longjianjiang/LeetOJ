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

// 给定矩阵，只有'X','O'. 将X包围的O需要被替换为X。
class Solution {
public:
    void solve_unionFind(vector<vector<char>>& board) {
		if (board.empty()) { return; }
		int col = board[0].size(), row = board.size();
		int count = col * row;

		vector<int> p(count, 0);
		vector<int> b(count, 0);

		auto find = [&](int i) {
			while (i != p[i]) {
				p[i] = p[p[i]];
				i = p[i];
			}
			return i;
		};

		auto unionf = [&](int i, int j) {
			int p1 = find(i), p2 = find(j);
			if (p1 != p2) {
				p[p2] = p1;
				if (b[p2] == 1) { b[p1] = 1; }
			}
		};

		for (int i = 0; i < count; ++i) {
			int x = i / col, y = i % col;
			p[i] = i;
			if (board[x][y] == 'O' &&
				(x == 0 || x == row-1 || y == 0 || y == col-1)) {
				b[i] = 1;
			}
		}

		for (int i = 0; i < count; ++i) {
			int x1 = i / col, y1 = i % col;
			int x2 = x1+1, y2 = y1+1;
			if (x2 < row && board[x1][y1] == board[x2][y1]) {
				unionf(i, i+col);
			}

			if (y2 < col && board[x1][y1] == board[x1][y2]) {
				unionf(i, i+1);
			}
		}

		for (int i = 0; i < count; ++i) {
			int x = i / col, y = i % col;
			if (board[x][y] == 'O' && b[find(i)] == 0) {
				board[x][y] = 'X';
			}
		}
    }

	// 使用dfs，从边界寻找到O，然后dfs搜索四周是否存在O，将O改成其他字符，
	// 进行第二次遍历，将O替换为X，此时的O是被#包围的，将其他字符替换回O。
    void solve_dfs(vector<vector<char>>& board) {
		if (board.empty()) { return; }

		int row = board.size(), col = board[0].size();
		int count = row * col;

		for (int i = 0; i < count; ++i) {
			int x = i / col, y = i % col;
			if (x == 0 || x == row-1 ||  y == 0 || y == col-1) {
				if (board[x][y] == 'O') { dfs(board, x, y); }
			}
		}

		for (int i = 0; i < count; ++i) {
			int x = i / col, y = i % col;
			if (board[x][y] == 'O') { board[x][y] = 'X'; }
			if (board[x][y] == '#') { board[x][y] = 'O'; }
		}
	}

	void dfs(vector<vector<char>>& board, int x, int y) {
		board[x][y] = '#';
		if (x+1 < board.size() && board[x+1][y] == 'O') { dfs(board, x+1, y); }
		if (x-1 > 0 && board[x-1][y] == 'O') { dfs(board, x-1, y); }
		if (y+1 < board[0].size() && board[x][y+1] == 'O') { dfs(board, x, y+1); }
		if (y-1 > 0 && board[x][y-1] == 'O') { dfs(board, x, y-1); }
	}

};


