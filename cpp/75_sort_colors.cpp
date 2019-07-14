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

// 给定0，1，2的数组，排序，不要使用计数的方式，同时要求时间复杂度为O(n);
// l，r 分别表示0和2的位置，idx从0开始遍历。
// 当nums[idx]==0，交换l，idx，l往后移动一位
// 当nums[idx]==2，交换r，idx，r往前移动一位
// 当nums[idx]==1, idx移动即可

class Solution {
public:
    void sortColors(vector<int>& nums) {
		if (nums.size() <= 1) { return; }

		int idx = 0, l = 0, r = nums.size()-1;
		while (idx <= r) {
			if (nums[idx] == 0) {
				swap(nums[idx++], nums[l++]);
			} else if (nums[idx] == 2) {
			    swap(nums[idx], nums[r--]);		
			} else {
				idx++;
			}
		}
    }
};


void unit_test() {
	Solution s;

	vector<int> nums = {2, 0, 2, 1, 1, 0};
	s.sortColors(nums);

	for (auto n: nums) {
		cout << n << " ";
	}
	cout << endl;
}

int main() {
	unit_test();
	return 0;
}
