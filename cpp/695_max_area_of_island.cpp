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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
		int rows = grid.size();
		if (rows == 0) { return 0; }
		int cols = grid[0].size();
		if (cols == 0) { return 0; }

		vector<int> arr(rows * cols, 0);
		for (int i = 0; i < arr.size(); ++i) {
			arr[i] = i;
		}

		auto findFunc = [&](int x) {
			while (x != arr[x]) {
				arr[x] = arr[arr[x]];
				x = arr[x];
			}
			return x;
		};
		auto unionFunc = [&](int i, int j) {
			int p = findFunc(i);
			int q = findFunc(j);
			if (p != q) {
				arr[q] = p;
			}
		};

		for (int x = 0; x < rows; ++x) {
			for (int y = 0; y < cols; ++y) {
                if (grid[x][y] != 1) { continue; }
				int i = x * cols + y;
				int x1 = x, y1 = y-1;
				if (y1 >= 0 && grid[x1][y1] == 1) {
					int j = x1 * cols + y1;
					unionFunc(j, i);
				}
				int x2 = x-1, y2 = y;
				if (x2 >= 0 && grid[x2][y2] == 1) {
					int j = x2 * cols + y2;
					unionFunc(j, i);
				}
			}
		}

		unordered_map<int, int> us;
		for (int i = 0; i < arr.size(); ++i) {
            int x = i / cols, y = i % cols;
			if (grid[x][y] == 1) {
                int p = findFunc(i);
                us[p] += 1;
                // us[arr[i]] += 1;
			}
		}
		int res = 0;
		for (auto item : us) {
			res = max(res, item.second);
		}

		return res;
    }
};
