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
    int findDuplicate(vector<int>& nums) {
		int nsize = nums.size();
		int l = 0, r = nsize - 1;
		// 数组范围是[1, n]
		while (l <= r) {
			int mid = l + (r - l) / 2;
			int cnt = 0;
			for (int i = 0; i < nsize; ++i) {
				if (nums[i] <= mid) { ++cnt; }
			}
			if (cnt > mid) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return l;
    }
};
