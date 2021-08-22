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

/*
 * 输入：
[
  [0,2,1,0],
  [0,1,0,1],
  [1,1,0,1],
  [0,1,0,1]
]
输出： [1,2,4]
 */
// 和Leetcode200类似，使用并查集。
class Solution {
private:
	vector<pair<int, int>> edges = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
		if (land.empty()) { return {}; }

		int row = land.size(), col = land[0].size();
		int cnt = row * col;
		vector<int> p(cnt, 0);
		for (int i = 0; i < cnt; ++i) { p[i] = i; }

		auto find = [&](int i) {
			while (i != p[i]) {
				p[i] = p[p[i]];
				i = p[i];
			}
			return i;
		};

		auto unionf = [&](int i, int j) {
			int p1 = find(i), p2 = find(j);
			if (p1 != p2) { p[p2] = p1; }
		};

		for (int i = 0; i < cnt; ++i) {
			int x1 = i / col, y1 = i % col;
			
			int x2 = x1 + 1, y2 = y1 + 1;
			if (x2 < row && land[x1][y1] == 0 && land[x2][y1] == 0) {
				unionf(i, i + col);
			}
			if (y2 < col && land[x1][y1] == 0 && land[x1][y2] == 0) {
				unionf(i, i + 1);
			}
			int x3 = x1 - 1, y3 = y1 + 1;
			if (x3 >= 0 && y3 < col && land[x1][y1] == 0 && land[x3][y3] == 0) {
				unionf(i, i - col + 1);
			}
			int x4 = x1 - 1, y4 = y1 - 1;
            if (x4 >= 0 && y4 >= 0 && land[x1][y1] == 0 && land[x4][y4] == 0) {
                unionf(i, i - col - 1);
            }
		}

		unordered_map<int, int> dict;
		for (int i = 0; i < cnt; ++i) {
			int x = i / col, y = i % col;
			if (land[x][y] == 0) {
				dict[find(i)]++;
			}
		}
		vector<int> res;
		for (auto v : dict) {
			res.push_back(v.second);
		}
		sort(res.begin(), res.end());

		return res;
    }
};
