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
1	2	3	4
5	6	7	8
9	10	11	12
13	14	15	16
--------------
1,2,3,4,8,12,16,15,14,13,9,5,1,6,7,11,10
*/
// 给定矩阵，从外向里以顺时针的顺序依次打印；
// 找出边界的四个点，按顺时针方向，依次去取；
class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
		int h = matrix.size(); if (h == 0) { return {}; }
		int w = matrix[0].size(); if (w == 0) { return {}; }

		vector<int> res;
		int bx = 0, ex = h-1;
		int by = 0, ey = w-1;

		while (true) {
			for (int i = by; i <= ey; ++i) { res.push_back(matrix[bx][i]); }
			if (++bx > ex) { break; }

			for (int i = bx; i <= ex; ++i) { res.push_back(matrix[i][ey]); }
			if (--ey < by) { break; }

			for (int i = ey; i >= by; --i) { res.push_back(matrix[ex][i]); }
			if (--ex < bx) { break; }

			for (int i = ex; i >= bx; --i) { res.push_back(matrix[i][by]); }
			if (++by > ey) { break; }
		}

		return res;
    }
};
