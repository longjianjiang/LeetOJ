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
				x += point[0]; y += point[1];
				if (x >= row || y >= col || x < 0 || y < 0 || visited[x][y]) { continue; }
				visited[x][y] = 1;
				if (heightMap[x][y] < maxHeight) { resVal += maxHeight - heightMap[x][y]; }
				pq.push(make_pair(heightMap[x][y], x * col + y));
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
