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
    int numSubarraysWithSum(vector<int>& nums, int goal) {
		int nsize = nums.size();
		if (nsize == 0) { return 0; }

		vector<int> prefix(nsize+1, 0);
		for (int i = 0; i < nsize; ++i) {
			prefix[i+1] = prefix[i] + nums[i];
		}

		int res = 0;
		unordered_map<int, int> dict;
		for (int i = 0; i < nsize; ++i) {
			int sum = prefix[i+1];
			if (sum == goal) {
				++res;
			}
			int diff = sum - goal;
			if (dict.find(diff) != dict.end()) {
				res += dict[diff];
			}
			dict[sum] += 1;
		}
		return res;
    }
};

void unit_test() {
	// nums = [1,0,1,0,1], goal = 2
	Solution s;
	vector<int> nums1 = {1, 0, 1, 0, 1};
	vector<int> nums2 = {0, 0, 0, 0, 0};
	cout << s.numSubarraysWithSum(nums1, 2) << endl;
	cout << s.numSubarraysWithSum(nums2, 0) << endl;
}

int main() {
	unit_test();
	return 0;
}
