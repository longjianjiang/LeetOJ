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

// 给定矩阵，求岛屿数量，所谓岛屿就是被0包围着的1的连通图。
// 1> 使用union find，先进行合并，然后查找1所构成的union有多少个。
// 2> 使用dfs，一次搜索递归的把周围的1改成其他字符，统计个数。
class Solution {
public:
	vector<pair<int, int>> edges = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

	// bfs
	void bfs(vector<vector<char>>& grid, int x, int y) {
		int row = grid.size();
		if (row == 0) { return; }
		int col = grid[0].size();
		if (col == 0) { return; }

		if (x < 0 || x >= row || y < 0 || y >= col) { return; }
		if (grid[x][y] != '1') { return; }

		grid[x][y] = '$';
		queue<pair<int, int>> q;
		q.push({x, y});

		while (!q.empty()) {
			int nsize = q.size();
			for (int i = 0; i < nsize; ++i) {
				auto point = q.front(); q.pop();
				int x2 = point.first, y2 = point.second;
				if (y2+1 < col && grid[x2][y2+1] == '1') {
					q.push({x2, y2+1});
					grid[x2][y2+1] = '$';
				}
				if (x2+1 < row && grid[x2+1][y2] == '1') {
					q.push({x2+1, y2});
					grid[x2+1][y2] = '$';
				}
				if (x2-1 >= 0 && grid[x2-1][y2] == '1') {
					q.push({x2-1, y2});
					grid[x2-1][y2] = '$';
				}
				if (y2-1 >= 0 && grid[x2][y2-1] == '1') {
					q.push({x2, y2-1});
					grid[x2][y2-1] = '$';
				}
			}
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		int row = grid.size();
		if (row == 0) { return 0; }
		int col = grid[0].size();
		if (col == 0) { return 0; }

		int res = 0;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (grid[i][j] == '1') {
					bfs(grid, i, j);
					res += 1;
				}
			}
		}

		return res;
	}

	// dfs
	void dfs(vector<vector<char>>& grid, int x, int y) {
		int row = grid.size();
		if (row == 0) { return; }
		int col = grid[0].size();
		if (col == 0) { return; }

		if (x < 0 || x >= row || y < 0 || y >= col) { return; }
		if (grid[x][y] != '1') { return; }

		grid[x][y] = '$';
		for (auto edge : edges) {
			int x1 = x + edge.first, y1 = y + edge.second;
			dfs(grid, x1, y1);
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		int row = grid.size();
		if (row == 0) { return 0; }
		int col = grid[0].size();
		if (col == 0) { return 0; }

		int res = 0;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (grid[i][j] == '1') {
					dfs(grid, i, j);
					res += 1;
				}
			}
		}

		return res;
	}

    int numIslands(vector<vector<char>>& grid) {
		int row = grid.size();
		if (row == 0) { return 0; }
		int col = grid[0].size();
		if (col == 0) { return 0; }

		int cnt = row * col;
		vector<int> p(cnt, 0);
		for (int i = 0; i < cnt; ++i) {
			p[i] = i;
		}

		auto findFunc = [&](int x) {
			while (x != p[x]) {
				p[x] = p[p[x]];
				x = p[x];
			}
			return x;
		};
		auto unionFunc = [&](int i, int j) {
			int p1 = findFunc(i), p2 = findFunc(j);
			if (p1 != p2) {
				p[p2] = p1;
			}
		};

		// 1-2, 2-2; 2-3;
		// 3-3;
		// p[1] = 2 != 3; p[1] = p[p[2]] = 3;
		// x = 3; p[3] = 3
		for (int x = 0; x < row; ++x) {
			for (int y = 0; y < col; ++y) {	
				if (grid[x][y] != '1') { continue; }
				int i = x * col + y;
				int x1 = x-1, y1 = y;
				if (x1 >= 0 && grid[x1][y1] == '1') {
					int j = x1 * col + y1;
					unionFunc(i, j);
				}
				int x2 = x, y2 = y-1;
				if (y2 >= 0 && grid[x2][y2] == '1') {
					int j = x2 * col + y2;
					unionFunc(i, j);
				}
			}
		}

		unordered_set<int> us;
		for (auto num : p) {
			int x = num / col, y = num % col;
			if (grid[x][y] == '1') {
				int x = findFunc(num);
				us.insert(x);
			}
		}
		return us.size();
    }
};
