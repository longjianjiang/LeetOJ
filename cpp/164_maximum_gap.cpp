#include <iostream>
#include <vector>

// 给定未排序的数组，要求返回排序后两两组合差值最大的。
// [3, 6, 9, 1] => 3
// 分桶，最大桶和最小桶，最大间隔为相邻的最小桶-最大桶的差值
class Solution {
public:
    int maximumGap(vector<int>& nums) {
		int nsize = (int)nums.size();
 		if (nsize < 2) { return 0; }       

		int maxNumber = nums[0], minNumber = nums[0];
		for (auto num: nums) {
			if (num > maxNumber) { maxNumber = num; }
			if (num < minNumber) { minNumber = num; }
		}
		if (maxNumber == minNumber) { return 0; }

		int bucketSize = (maxNumber - minNumber) / nsize + 1; 
		int bucketCount = (maxNumber - minNumber) / bucketSize + 1; 
		
		vector<int> bucketMin(bucketCount, INT_MAX);
		vector<int> bucketMax(bucketCount, INT_MIN);

		for(auto num: nums) {
			int idx = (num - minNumber) / bucketSize;

			bucketMin[idx] = min(bucketMin[idx], num);
			bucketMax[idx] = max(bucketMax[idx], num);
		}

		// 3-1 / 3 = 0 
		// bMin[1, 6, 9]
		// bMax[3, 6 ,9]
		// bMin[i] - bMax[i-1]

		int res = 0;
        int lastIdx = 0;
		for (int i = 1; i < bucketCount; ++i) {
            if (bucketMin[i] == INT_MAX) { continue; }
			int diff = bucketMin[i] - bucketMax[lastIdx];
			res = diff > res ? diff : res;
            lastIdx = i;
		}
		return res;
    }
};
