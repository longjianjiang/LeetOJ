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
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
		int row = grid.size();
		if (row == 0) { return 0; }
		int col = grid[0].size();

		int cnt = row * col;
		vector<int> p;
		for (int i = 0; i < cnt; ++i) {
			p.push_back(i);
		}

		auto findf = [&](int i) {
			while (i != p[i]) {
				p[i] = p[p[i]];
				i = p[i];
			}
			return i;
		};
		auto unionf = [&](int i, int j) {
			int p1 = findf(i), p2 = findf(j);
			if (p1 != p2) { p[p2] = p1; }
		};

		for (int i = 0; i < cnt; ++i) {
			int x1 = i / col, y1 = i % col;
			int x2 = x1+1, y2 = y1+1;

			if (x2 < row && grid[x1][y1] == '1' && grid[x2][y1] == '1') {
				unionf(i, i+col);
			}
			if (y2 < col && grid[x1][y1] == '1' && grid[x1][y2] == '1') {
				unionf(i, i+1);
			}
		}

		unordered_set<int> us;
		for (int i = 0; i < cnt; ++i) {
			int x1 = i / col, y1 = i % col;
			if (grid[x1][y1] == '1') { us.insert(findf(i)); }
		}

		return us.size();
    }
};
