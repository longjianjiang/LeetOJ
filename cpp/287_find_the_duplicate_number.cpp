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

// 给定n+1个数，取值范围是[1,n]。找出重复的数字
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0;
		int nsize = (int)nums.size();

		while (1) {
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast) { break; }
		}

		auto tmp = 0;
		while (tmp != slow) {
			tmp = nums[tmp];
			slow = nums[slow];
		}

		return slow;
    }

	int findDuplicate_bs(vector<int>& nums) {
		int left = 1, right = (int)nums.size()-1;
		while (left <= right) {
			int mid = left + (right - left)/2;
			int cnt = 0;
			for (int i = 0; i < nums.size(); ++i) {
				if (nums[i] <= mid) { ++cnt; }
			}
			if (cnt > mid) {
				right = mid-1;
			} else {
				left = mid + 1;
			}
		}
		return left;
	}

	int findDuplicate_bit(vector<int>& nums) {
		int nsize = (int)nums.size()-1;
		int res = 0;
		for (int i = 0; i < 32; ++i) {
			int bit = 1 << i, a = 0, b = 0;
			for (int j = 0; j <= nsize; ++j) {
				if (j > 0 && j & bit) { ++a; }
				if (nums[j] & bit) { ++b; }
			}
			if (b > a) { res |= bit; }
		}
		return res;
	}
};

void unit_test() {
	Solution s;
	vector<vector<int>> arr = {{4, 3, 1, 4, 2}, {1, 3, 4, 2, 2}, {3, 1, 3, 4, 2}};

	for (auto nums : arr) {
		cout << s.findDuplicate_bs(nums) << endl;
	}
}

int main() {
	unit_test();
	return 0;
}
