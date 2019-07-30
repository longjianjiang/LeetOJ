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

// 给定二维矩阵，由0和1组成，岛屿是路径由1组成四周被0包围。求岛屿个数，其实就是求连通的路径个数，当另一个路径四周全是0，这个时候就成了一个新的岛屿。
// 依然使用并查集，将一个岛屿组成一个集合，最后求多少个集合即可。
// 首先从头开始遍历，进行相邻的合并；第二次遍历将1的点find parent，最后返回parent个数即可。
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
		if (grid.empty()) { return 0; }

		int row = grid.size(), col = grid[0].size();
		int count = row * col;
		vector<int> p(count, 0);

		for (int i = 0; i < count; ++i) {
			p[i] = i;
		}

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
			}
		};

		for (int i = 0; i < count; ++i) {
			int x1 = i / col, y1 = i % col;
			int x2 = x1+1, y2 = y1+1;

			if (x2 < row && grid[x1][y1] == '1' && grid[x2][y1] == '1') {
				unionf(i, i+col);
			}
			if (y2 < col && grid[x1][y1] == '1' && grid[x1][y2] == '1') {
				unionf(i, i+1);
			}
		}

		unordered_set<int> ps;
		for (int i = 0; i < count; ++i) {
			int x = i / col, y = i % col;
			if (grid[x][y] == '1') {
				ps.insert(find(i));
			}
		}
		return ps.size();
    }
};
