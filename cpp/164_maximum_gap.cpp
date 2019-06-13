#include <iostream>
#include <vector>

// 给定未排序的数组，要求返回排序后两两组合差值最大的。
// [3, 6, 9, 1] => 3

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

		

    }
};
