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
	int findKth(vector<int>& nums1, vector<int>& nums2, int k) {
		int nsize1 = nums1.size();
		int nsize2 = nums2.size();

		if (nsize1 > nsize2) {
			return findKth(nums2, nums1, k);
		}
		if (nsize1 == 0) {
			return nums2[k];
		} else if (k == 0) {
			return min(nums1[0], nums2[0]);
		}

		int pa = min(nsize1-1, k / 2);
		int pb = k - pa;
		if (nums1[pa] < nums2[pb]) {
			return findKth(vector<int>(nums1.begin()+pa, nums1.end()) , nums2, k - pa);
		} else if (nums1[pa] > nums2[pb]) {
			return findKth(nums1, vector<int>(nums2.begin()+pb, nums2.end()), k - pb);
		} else {
			return nums1[pa];
		}
	}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int nsize1 = nums1.size();
		int nsize2 = nums2.size();

		int len = nsize1 + nsize2;
		if (len % 2 == 1) {
			return findKth(nums1, nums2, len / 2);
		} else {
			return (findKth(nums1, nums2, len / 2 - 1) + findKth(nums1, nums2, len / 2)) / 2.0;
		}
    }
};
