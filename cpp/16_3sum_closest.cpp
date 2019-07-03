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

// 给定数组和target，求三个一组和最接近target的和
// 将数组排序，从头开始遍历，每次left=i+1, right=size-1，每次根据sum求diff，返回diff最小的sum即可
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int res = nums[0] + nums[1] + nums[2];
		int diff = abs(res - target);
	
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i) {
			int l = i+1, r = nums.size()-1;
			
			while (l < r) {
				int sum = nums[i] + nums[l] + nums[r];
				if (sum == target) {
					return target;
				} else if (sum > target) {
					r--;	
				} else {
					l++;
				}
				int tmp = abs(sum-target);
				if (tmp < diff) {
					diff = tmp;
					res = sum;
				}
			}
		}

		return res;
    }
};

void unit_test() {
	Solution s;

	vector<int> nums = {-1, 2, 1, -4};

	assert(s.threeSumClosest(nums, 1) == 2);
}

int main() {
	unit_test();
	return 0;
}
