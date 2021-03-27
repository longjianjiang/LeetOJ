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

// [ref](https://www.cnblogs.com/boring09/p/4231906.html)
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

如何安装快速键盘:
1) 点击👆的「键盘」;
2) 打开「快速键盘」, 「允许完全访问」开关;

* 如果没有显示「键盘」，请上滑关闭设置应用，重新打开这个页面;
*「允许完全访问」不开启无法同步您之前输入的快捷文本；
* 我们保证不会收集任何您的个人数据;

How to install Quick Keyboard:
1) Tap 'Keyboards' button above 👆.
2) Toggle 'Quick Keyboard' and 'Allow Full Access' on.

* If there is no 'Keyboards' button, please swipe up to force quit settings app and reopen it.
* Without full access rights, we cannot synchronize the shortcut text you entered before.
* We will never collect any of your private data.