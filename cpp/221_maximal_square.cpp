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

// 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
// 遍历，对每个节点尝试正方形构建，返回最大宽度。
class Solution {
public:
	int helper(int x, int y, vector<vector<char>> matrix, int len) {
		int rows = matrix.size();
		if (rows == 0) { return 0; }
		int cols = matrix[0].size();
		if (cols == 0) { return 0; }

		vector<vector<int>> arr;
		int x1 = x + len, y1 = y + len;
		arr.push_back({x1, y1});
		for (int x2 = x; x2 < x1; ++x2) {
			arr.push_back({x2, y1});
		}
		for (int y2 = y; y2 < y1; ++y2) {
			arr.push_back({x1, y2});
		}

		bool flag = true;
		for (auto point : arr) {
			int x = point[0], y = point[1];
			if (x < rows && y < cols && matrix[x][y] == '1') {

			} else {
				flag = false;
				break;
			}
		}
		if (flag) {
			return helper(x, y, matrix, len + 1);
		} else {
			return len;
		}
	}

    int maximalSquare(vector<vector<char>>& matrix) {
		int rows = matrix.size();
		if (rows == 0) { return 0; }
		int cols = matrix[0].size();
		if (cols == 0) { return 0; }

		int len = 0;
		for (int x = 0; x < rows; ++x) {
			for (int y = 0; y < cols; ++y) {
				if (matrix[x][y] == '1') {
					int tmp = helper(x, y, matrix, 1);
					len = max(tmp, len);
				}
			}
		}

		return len * len;
    }
};


void unit_test() {
	Solution s;

	vector<vector<char>> matrix;
	matrix.push_back({'1','0','1','0','0'});
	matrix.push_back({'1','0','1','1','1'});
	matrix.push_back({'1','1','1','1','1'});
	matrix.push_back({'1','0','0','1','0'});

	cout << s.maximalSquare(matrix) << endl;
}

int main() {
	unit_test();
	return 0;
}
