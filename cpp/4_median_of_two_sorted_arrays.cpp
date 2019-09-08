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

// 给定两个有序数组，返回两个数组组合后的中位数。
// 可以化解成在两个有序数组中寻找第k个元素：
// 1. 当某个数组为空，直接返回[k-1];
// 2. 当k=1，返回min(nums1[0], nums2[0]);
// 3. 二分，减小k同时截取数组；
class Solution {
public:
	int findkth(vector<int> nums1, vector<int> nums2, int k) {
		if (nums1.empty()) { return nums2[k-1]; }
		if (nums2.empty()) { return nums1[k-1]; }
		if (k == 1) { return min(nums1[0], nums2[0]); }

	    int m = (int)nums1.size(), n = (int)nums2.size();
		int i = min(m, k/2), j = min(n, k/2);

		if (nums1[i-1] > nums2[j-1]) {
			return findkth(nums1, vector<int>(nums2.begin()+j, nums2.end()), k-j);
		} else {
			return findkth(vector<int>(nums1.begin()+i, nums1.end()), nums2, k-i);
		}
	}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	    int m = (int)nums1.size(), n = (int)nums2.size();
		int i = (m+n+1) / 2, j = (m+n+2)/2;

		return (findkth(nums1, nums2, i) + findkth(nums1, nums2, j)) / 2.0;
    }
};

void unit_test() {
	Solution s;
}

int main() {
	unit_test();
	return 0;
}
