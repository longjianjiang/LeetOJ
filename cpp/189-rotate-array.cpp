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
	void rotate(vector<int>& nums, int k) {
        if (k == 0) { return; }
		int nsize = nums.size();
		if (nsize <= 1) { return; }
		int idx = nsize - (k % nsize);
        if (idx == 0) { return; }
        
        auto reverseFunc = [&](vector<int>& nums, int l, int r) {
            while (l < r) {
                swap(nums[l], nums[r]);
                ++l; --r;
            }
        };
        
        reverseFunc(nums, 0, idx-1);
        reverseFunc(nums, idx, nsize-1);
        reverseFunc(nums, 0, nsize-1);
	}
	
    void rotate(vector<int>& nums, int k) {
    	int nsize = nums.size();
		if (nsize <= 1) { return; }
		int idx = nsize - (k % nsize);
        
		vector<int> arr1, arr2;
		for (int i = 0; i < nsize; ++i) {
			if (i < idx) {
				arr2.push_back(nums[i]);
			} else {
				arr1.push_back(nums[i]);
			}
		}

		int pos = 0;
		for (int i = 0; i < arr1.size(); ++i) {
			nums[pos++] = arr1[i];
		}
		for (int i = 0; i < arr2.size(); ++i) {
			nums[pos++] = arr2[i];
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
	vector<int> nums1 = {1,2,3,4,5,6,7};
	s.rotate(nums1, 3);

	show_arr_one_dimensional(nums1);
}

int main() {
	unit_test();
	return 0;
}
