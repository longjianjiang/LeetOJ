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

// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

// 1> 遍历矩阵；
// 2> bfs;
class Solution {
private:
	vector<pair<int, int>> edges = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
	int pointSum(int x, int y) {
		int res = 0;
		while (x > 0) {
			res += (x % 10);
			x /= 10;
		}
		while (y > 0) {
			res += (y % 10);
			y /= 10;
		}
		return res;
	}

    int movingCount(int m, int n, int k) {
		vector<vector<int>> visited(m, vector<int>(n, 0));
		queue<pair<int, int>> q; q.push({0, 0}); visited[0][0] = 1;
		int res = 0;

		while (!q.empty()) {
			auto point = q.front(); q.pop();
			int x = point.first, y = point.second;
			++res;

			for (auto edge: edges) {
				int x1 = x+edge.first, y1 = y+edge.second;
				if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) { continue; }
				if (visited[x1][y1] || pointSum(x1, y1) > k) { continue; }
				q.push({x1, y1}); visited[x1][y1] = 1;
			}
		}

		return res;
    }
};
