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
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
输入: [2,1,5,6,2,3]
输出: 10
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		if (heights.empty()) { return 0; }

		heights.push_back(0);
		stack<int> stk;
		int w = 0, h = 0;
		int maxArea = 0;
		int nsize = heights.size();

		for (int i = 0; i < nsize; ++i) {
			if (stk.empty() || heights[i] >= heights[stk.top()]) {
				stk.push(i);
			} else {
				while (!stk.empty() && heights[i] <= heights[stk.top()]) {
					int h = heights[stk.top()];
					stk.pop();
					int w = stk.empty() ? i : (i - stk.top() - 1);
					maxArea = max(maxArea, w * h);
				}
				stk.push(i);
			}
		}

		return maxArea;
    }
};
