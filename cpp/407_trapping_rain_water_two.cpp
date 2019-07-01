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

// 二维的取坑，首先必须大于等于3*3才能形成坑，矩形的边界是无法形成坑的，
// 所以从边界开始，依次遍历最小的高度，如果上下左右四个周围的点存在并且未被访问过，加入堆中，同时标记为已访问，这个时候如果周围的高度小于当前最小高度，那么差值部分就是形成的坑；
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
		if (heightMap.empty()) { return 0; }
        int row = (int)heightMap.size(), col = heightMap[0].size();

        if (row < 3 || col < 3) { return 0; }

		int resVal = 0, maxHeight = INT_MIN;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<vector<int>> visited(row, vector<int>(col, 0));
		vector<vector<int>> around{ {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if ( !(i == 0 || i == row - 1 || j == 0 || j == col - 1) ) { continue; }
				pq.push(make_pair(heightMap[i][j], i * col + j));
				visited[i][j] = 1;
			}
		}

		while (!pq.empty()) {
			auto item = pq.top(); pq.pop();
			int height = item.first, x = item.second / col, y = item.second % col;
			maxHeight = max(maxHeight, height);

			for (auto point: around) {
				int xx = x + point[0], yy = y + point[1];
				if (xx >= row || yy >= col || xx < 0 || yy < 0 || visited[xx][yy]) { continue; }
				visited[xx][yy] = 1;
				if (heightMap[xx][yy] < maxHeight) { resVal += maxHeight - heightMap[xx][yy]; }
				pq.push(make_pair(heightMap[xx][yy], xx * col + yy));
			}
		}

        return resVal;
    }
};

void unit_test() {
	Solution s;

	vector<vector<int>> heights = {{1, 4, 3, 1, 3, 2},
								   {3, 2, 1, 3, 2, 4}, 
								   {2, 3, 3, 2, 3, 1}};
	assert(s.trapRainWater(heights) == 4);
}

int main() {
	unit_test();
	return 0;
}
