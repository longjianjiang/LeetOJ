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
	vector<pair<int, int>> edges = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
	int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& cache) {
		if (cache[x][y] > 0) { return cache[x][y]; }	

		int rows = matrix.size();
		if (rows == 0) { return 0; }
		int cols = matrix[0].size();
		if (cols == 0) { return 0; }

		int res = 1;
		for (auto edge : edges) {
			int x1 = x + edge.first, y1 = y + edge.second;
			if (x1 < 0 || x1 >= rows || y1 < 0 || y1 >= cols) { continue; }
			if (matrix[x1][y1] <= matrix[x][y]) { continue; }
			int tmp = 1 + dfs(matrix, x1, y1, cache);
			res = max(res, tmp);
		}
		cache[x][y] = res;
		return res;
	}

    int longestIncreasingPath(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		if (rows == 0) { return 0; }
		int cols = matrix[0].size();
		if (cols == 0) { return 0; }
		
		int res = 0;
		vector<vector<int>> cache(rows, vector<int>(cols, 0));
		for (int x = 0; x < rows; ++x) {
			for (int y = 0; y < cols; ++y) {
				int tmp = dfs(matrix, x, y, cache);
				res = max(res, tmp);
			}
		}

		return res;
    }
};
