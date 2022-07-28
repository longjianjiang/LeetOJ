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
Input: nums = [3,30,34,5,9]
Output: "9534330"
 */

// 9, 5, 34, 3, 30
class Solution {
public:
    string largestNumber(vector<int>& nums) {
		string res;

		sort(nums.begin(), nums.end(), [](const int lhs, const int rhs) {
			string l = to_string(lhs) + to_string(rhs);
			string r = to_string(rhs) + to_string(lhs);
			// 330, 303
			return l > r;
		});

		for (auto num : nums) {
			res += to_string(num);
		}
		return res;
    }
};

void unit_test() {
	Solution s;

	vector<int> nums = {3, 30, 34, 5, 9};
	cout << s.largestNumber(nums) << endl;
}

int main() {
	unit_test();
	return 0;
}
