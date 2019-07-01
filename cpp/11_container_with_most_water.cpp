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

// 给定一组数，求坐标中形成的最大面积是多少。
// 左右指针，每次计算出当前矩形的面积，固定高的一边继续移动，重复计算，直到结束
class Solution {
public:
    int maxArea(vector<int>& height) {
		if (height.empty()) { return 0; }
		if (height.size() == 1) { return 1 * height[0]; }

		int left = 0, right = (int)height.size()-1;
		int resVal = 0;
		while (left <= right) {
			int h = min(height[left], height[right]);

			int area = h * (right-left);
			resVal = max(resVal, area);

			height[left] <= height[right] ? left++ : right--;
		}
		
		return resVal;
    }
};

void unit_test() {
	vector<int> v = {1,8,6,2,5,4,8,3,7};

	Solution s;
	assert(s.maxArea(v) == 49);
}

int main() {
	unit_test();
	return 0;
}
