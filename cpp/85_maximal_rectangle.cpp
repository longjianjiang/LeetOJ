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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) { return 0; }
		int col = matrix[0].size();
		if (col == 0) { return 0; }

		vector<int> heights;
		for (int i = 0; i < col; ++i) {
			int height = 0;
			for (int j = 0; j < row; ++j) {
				if (matrix[i][j] == '1') { ++height; }
			}
			heights.push_back(height);
		}

		return largestRectangleArea(heights);
    }

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
