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


// 乱序数组中返回第一个未出现的正数
// 法1: 一次遍历将所有树存入set，同时找到max，第二次遍历，从1到max，如果某个树不在set中，直接返回该数，否则返回max+1；
// 法2: 使用swap，将数组从0开始依次存储1，2，3依次增加1。第二次遍历，如果某个位置不是i+1，直接返回i+1，否则返回size+1；
// swap(nums[nums[i]-1], nums[i])


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		int nsize = (int)nums.size();

		int i = 0;
		while (i < nsize) {
			if (nums[i] != i+1 && nums[i] >= 1 && nums[i] <= nsize && nums[nums[i]-1] != nums[i]) {
				swap(nums[nums[i]-1], nums[i]);
			} else {
				++i;
			}
		}

		for (i = 0; i < nsize; ++i) {
			if (nums[i] != i+1) { return i+1; }
		}
		return nsize+1;
    }
};

void unit_test() {
	Solution s;

	vector<int> nums1 = {1, 2, 0};
	vector<int> nums2 = {3, 4, -1, 1};
	vector<int> nums3 = {2, 4, 5};

	cout << s.firstMissingPositive(nums1) << endl;
	cout << s.firstMissingPositive(nums2) << endl;
	cout << s.firstMissingPositive(nums3) << endl;
}

int main() {
	unit_test();
	return 0;
}
