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
    int findLengthOfLCIS(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize <= 1) { return nsize; }

		int l = 0, r = 1;
		int res = 1;
		// [1,3,5,4,7]
		while (r < nsize) {
			if (nums[r] > nums[r-1]) {
				res = max(res, r-l+1);
			} else {
				l = r;
			}
			++r;
		}
		return res;
    }
};
