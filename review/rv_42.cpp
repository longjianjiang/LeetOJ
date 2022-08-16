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
    int trap(vector<int>& height) {
		int nsize = height.size();
		if (nsize <= 2) { return 0; }

		int l = 0, r = nsize - 1;
		int res = 0, edgeHeight = 0;
		while (l <= r) {
			int tmp = min(height[l], height[r]);
			if (tmp < edgeHeight) {
				res += edgeHeight - tmp;
			} else {
				edgeHeight = tmp;
			}
			if (height[l] < height[r]) {
				++l;
			} else {
				--r;
			}
		}
		return res;
    }
};
