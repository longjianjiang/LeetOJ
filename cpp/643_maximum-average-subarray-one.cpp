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
    double findMaxAverage(vector<int>& nums, int k) {
		int nsize = nums.size();
		if (nsize < k) { return 0; }
		if (nsize == k) {
			int sum = 0;
			for (int i = 0; i < nsize; ++i) {
				sum += nums[i];
			}
			return (double)sum / k;
		}
		int l = 0, r = 0;
		int sum = 0;
		int res = numeric_limits<int>::min();;
		//  [1,12,-5,-6,50,3]
		while (r < nsize) {
			sum += nums[r];
			int len = r - l + 1;
			if (len == k) {
				res = max(res, sum);
				sum -= nums[l];
				++l;
			} 
			++r;
		}
		return (double)res / k;
    }
};

void unit_test() {
	Solution s;
	vector<int> nums1 =  {1,12,-5,-6,50,3};
	cout << s.findMaxAverage(nums1, 4) << endl;
}

int main() {
	unit_test();
	return 0;
}
