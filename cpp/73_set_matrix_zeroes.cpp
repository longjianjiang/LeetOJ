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

// 给定二维矩阵，要求将矩阵中为0的所在行和所在列都设为零。
// 首先记录为零的行和列，然后重制即可。
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) { return; }
		int h = matrix.size(), w = matrix[0].size();
		unordered_set<int> zrow, zcol;

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (matrix[i][j] == 0) { zrow.insert(i); zcol.insert(j); }
			}
		}

		for (auto row : zrow) {
			for (int i = 0; i < w; ++i) { matrix[row][i] = 0; }
		}
		for (auto col : zcol) {
			for (int i = 0; i < h; ++i) { matrix[i][col] = 0; }
		}
    }
};
