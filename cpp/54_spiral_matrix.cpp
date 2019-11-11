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
1 2 3
4 5 6
7 8 9
*/

// 给定m*n的矩阵，返回螺旋的排列，例如👆结果是[1, 2, 3, 6, 9, 8, 7, 4, 5]
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.empty() || matrix[0].empty()) { return res; }
		
		int bx = 0, ex = matrix[0].size()-1;
		int by = 0, ey = matrix.size()-1;

		while (true) {
			// >
			for (int i = bx; i <= ex; ++i) {
				res.push_back(matrix[by][i]);
			}
			if (++by > ey) { break; }
			// v
			for (int i = by; i <= ey; ++i) {
				res.push_back(matrix[i][ex]);
			}
			if (--ex < bx) { break; }
			// <
			for (int i = ex; i >= bx; --i) {
				res.push_back(matrix[ey][i]);
			}
			if (--ey < by) { break; }
			// ^
			for (int i = ey; i >= by; --i) {
				res.push_back(matrix[i][bx]);
			}
			if (++bx > ex) { break; }
		}

		return res;
    }
};
