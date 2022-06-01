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
    bool isPalindrome(int x) {
		if (x < 0) { return false; }
		if (x < 10) { return true; }

		vector<int> nums;
		while (x) {
			int num = x % 10;
			nums.push_back(num);
			x /= 10;
		}

		int nsize = nums.size();
		int l = 0, r = nsize - 1;
		while (l < r) {
			if (nums[l] != nums[r]) { return false; }
			++l;
			--r;
		}
		return true;
    }
};
