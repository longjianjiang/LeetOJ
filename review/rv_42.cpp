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

		int idx = 0;
		while (height[idx] <= 0) {
			++idx;
		}
		stack<int> stk;
		int res = 0;
		// 1 2 3
		while (idx < nsize) {
			int tmp = height[idx];
			if (stk.empty() || tmp < height[stk.top()]) {
				// 保证左边界是最高的
				stk.push(idx++);
			} else {
				int top = height[stk.top()]; stk.pop();
				if (stk.empty()) { continue; }
				int areaH = min(height[stk.top()], tmp) - top; 
				int areaW = idx - stk.top() - 1;
				res += (areaW * areaH);
			}
		}
		return res;
	}

    int trap(vector<int>& height) {
		int nsize = height.size();
        if (nsize < 3) { return 0; }

        int l = 0, r = nsize - 1;
        int res = 0, borderH = 0;
        while (l <= r) {
            int tmp = min(height[l], height[r]);
            if (tmp < borderH) {
                res += (borderH - tmp);
            } else {
                borderH = tmp;
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
