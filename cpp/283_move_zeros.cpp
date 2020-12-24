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

/*
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

// [0, 1, 0, 3, 12]

// [1, 2, 3, 0, 0]

// [1, 0, 0, 2, 3, 0, 4]
// [1, 2, 3, 0, 0, 0, 4]


// 给定数组，要求移动数组中的所有0到末尾，同时要求不能更改其他数字的相对位置。空间复杂度O(1)。
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize < 2) { return; }

		int left = 0;
		while (left < nsize) { 
			if (nums[left] == 0) { break; }
			++left;
		}
		int right = left + 1;
		while (right < nsize) {
			while (right < nsize && nums[right] == 0) { ++right; }
			if (right >= nsize) { break; }

			// [left, right) 
			// [right, right_right)
			int right_right = right;
			while (right_right < nsize && nums[right_right] != 0) { ++right_right; }

			int left_idx = left;
			int right_idx = right;
			while (right_idx < right_right) { nums[left_idx++] = nums[right_idx++];}
			left_idx = left + (right_right - right);
			left = left_idx;
			while (left_idx < right_right) { nums[left_idx++] = 0; }
			right = right_right;
		}
	}

	void moveZeroes_2(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize < 2) { return; }

		int pos = 0;
		for (int i = 0; i < nsize; ++i) {
			if (nums[i] != 0) { nums[pos++] = nums[i]; }
		}
		for (int i = pos; i < nsize; ++i) {
			nums[i] = 0;
		}
	}
};

void show_arr_one_dimensional(vector<int> arr) {
	cout << "[";
	for (int i = 0; i < arr.size(); ++i) {
		int num = arr[i];
		if (i == arr.size()-1) {
			cout << num;
		} else {
			cout << num << " ";
		}
	}
	cout << "]\n";
}

void show_arr_two_dimensional(vector<vector<int>> arr) {
	for (auto v: arr) {
		show_arr_one_dimensional(v);
	}
}

void unit_test() {
	Solution s;

	vector<int> list1 = {0, 1, 0, 3, 12};
	vector<int> list2 = {1, 2, 3, 0, 0};
	vector<int> list3 = {1, 0, 0, 2, 3, 0, 4};

	s.moveZeroes_2(list1);
	s.moveZeroes_2(list2);
	s.moveZeroes_2(list3);

	show_arr_one_dimensional(list1);
	show_arr_one_dimensional(list2);
	show_arr_one_dimensional(list3);
}

int main() {
	unit_test();
	return 0;
}
