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
    int maxSubArray(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize == 0) { return 0; }
		if (nsize == 1) { return nums[0]; }
		
		int maxSum = nums[0];
		int dpSum = maxSum;
		for (int i = 1; i < nsize; ++i) {
			int tmp = nums[i];
			dpSum = max(tmp, tmp + dpSum);
			maxSum = max(maxSum, dpSum);
		}

		return maxSum;
    }
};
