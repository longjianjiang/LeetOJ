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
		int slow = 0, fast = 0;
		int nsize = (int)nums.size();

		while (slow != fast) {
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		auto tmp = 0;
		while (tmp != slow) {
			tmp = nums[tmp];
			slow = nums[slow];
		}

		return slow;
    }

	int findDuplicate_bs(vector<int>& nums) {
		int left = 0, right = (int)nums.size()-1;
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
