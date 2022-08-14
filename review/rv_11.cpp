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
    int maxArea(vector<int>& height) {
		int nsize = height.size();
		if (nsize <= 1) { return 0; }
		if (nsize == 2) { return min(height[0], height[1]); }

		int res = 0;
		int l = 0, r = nsize - 1;
		while (l <= r) {
			int w = r - l;
			int h = min(height[l], height[r]);
			int tmp = w * h;
			res = max(res, tmp);

			if (height[l] < height[r]) {
				++l;
			} else {
				--r;
			}
		}
		return res;
    }
};
