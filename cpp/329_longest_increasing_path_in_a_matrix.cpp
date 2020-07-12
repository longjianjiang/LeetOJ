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

// 给定一个整数矩阵，找出最长递增路径的长度。
// 对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

// 1> dfs，以矩阵中任意节点作为起点去寻找最大的长度，返回结果最长的；
class Solution {
private:
	vector<pair<int, int>> edges = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
	int dfs(vector<vector<int>>& matrix, vector<vector<int>>& cache, int row, int col, int x, int y) {
		if (cache[x][y] > 0) { return cache[x][y]; }

		int res = 1;
		for (auto edge: edges) {
			int x1 = x+edge.first, y1 = y+edge.second;
			if (x1 < 0 || x1 >= row || y1 < 0 || y1 >= col) { continue; }
			if (matrix[x][y] >= matrix[x1][y1]) { continue; }
			int path = 1 + dfs(matrix, cache, row, col, x1, y1);
			res = max(path, res);
		}

		cache[x][y] = res;
		return res;
	}

    int longestIncreasingPath(vector<vector<int>>& matrix) {
		int row = matrix.size();
		if (row == 0) { return 0; }
		int col = matrix[0].size();
		if (col == 0) { return 0; }

		vector<vector<int>> cache(row, vector<int>(col, 0));
		int res = 0;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				int num = dfs(matrix, cache, row, col, i, j);
				res = max(res, num);
			}
		}

		return res;
    }
};
