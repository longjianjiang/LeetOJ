#include <iostream>

using namespace std;

// 给定一个数组，数组中的数的范围为0-n，n为数组的size，让我们找出range中缺少的那个数字

// 一个方法就是先求出当前数字的和记做sum1，然后根据等差数列的前n项和求出sum2，所以缺少的数字就是sum2-sum1,
// 等差数列求和公式：Sn = n * (a0 + an) / 2.

// 另一个方法利用异或，我们新建一个数组从0-n，与原来的数组中每个元素异或，因为相同的数异或为0，所以最后剩下的那个数就是缺少的。

// 看到另一种方法使用二分查找

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum1 = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size() + 1;
        int sum2 = n*(0+n-1)/2;

        return sum2 - sum1;
    }

    int missingNumberVersionTwo(vector<int>& nums) {
    	int res = 0;
    	for (int i = 0; i < nums.size(); ++i) {
    		res ^= (i ^ nums[i]);
    	}
    	res ^= nums.size();

    	return res;
    }

    int missingNumberVersionThree(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	int left = 0, right = nums.size();
    	while (left < right) {
    		int mid = left + (right - left) / 2;
    		if (nums[mid] > mid) {
    			right = mid;
    		} else {
    			left = mid + 1;
    		}
    	}

    	return right;
    }
 
};