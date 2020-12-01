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

// 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
// 1> 首先找出这些点构成的矩形区域, 然后挨个遍历，这种方式太耗时；
// 2> 两点确定一条直线，所以确定两点，然后遍历所有点判断是否在同一直线；
// (y-y1)/(x-x1) == (y2-y1)/(x2-x1)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
		int nsize = points.size();
		if (nsize < 3) { return nsize; }

		int res = 2;
		for (int i = 0; i < nsize-1; ++i) {
			for (int j = i+1; j < nsize; ++j) {
				long x1 = points[i][0], y1 = points[i][1];
				long x2 = points[j][0], y2 = points[j][1];
				if (x1 == x2 && y1 == y2) { ++x2; ++y2; }

				int cnt = 0;
				for (int k = 0; k < nsize; ++k) {
					long x = points[k][0], y = points[k][1];
					if ((y-y1)*(x2-x1) == (y2-y1)*(x-x1)) {
						++cnt;
					}
				}

				res = max(res, cnt);
			}
		}

		return res;
    }
};
