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

template<typename T>
void show_arr_one_dimensional(vector<T> arr) {
	cout << "[";
	for (int i = 0; i < arr.size(); ++i) {
		T num = arr[i];
		if (i == arr.size()-1) {
			cout << num;
		} else {
			cout << num << " ";
		}
	}
	cout << "]\n";
}

template<typename T>
void show_arr_two_dimensional(vector<vector<T>> arr) {
	for (auto v: arr) {
		show_arr_one_dimensional(v);
	}
}

// 给定有序数组，原地删除重复的元素；
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize <= 1) { return 1; }

		int l = 0;
		while (l < nums.size()) {
			while (l + 1 < nums.size() && nums[l] == nums[l + 1]) {
				nums.erase(nums.begin() + l);
			}
			++l;
		}
		return nums.size();
    }
};


void unit_test() {
	Solution s;

	vector<int> nums1 = {1, 1, 2};
	cout << s.removeDuplicates(nums1) << endl;
	show_arr_one_dimensional(nums1);

	return;
	vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
	cout << s.removeDuplicates(nums2) << endl;
	show_arr_one_dimensional(nums2);
}

int main() {
	unit_test();
	return 0;
}
