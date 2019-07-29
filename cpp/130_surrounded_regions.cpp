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
};


