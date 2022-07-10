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
    bool checkSubarraySum(vector<int>& nums, int k) {
		int nsize = nums.size();
		if (nsize < 1) { return false; }

		vector<int> prefix(nsize + 1, 0);
		for (int i = 0; i < nsize; ++i) {
			prefix[i+1] = prefix[i] + nums[i];
		}

		unordered_map<int, int> dict;
		for (int i = 0; i < nsize; ++i) {
			int sum = prefix[i+1];
			if (i > 0 && sum % k == 0) {
				return true;
			}
			int remainder = sum % k;
			if (dict.find(remainder) != dict.end()) {
				int diff = i - dict[remainder];
				if (diff >= 2) {
					return true;
				}
			} else {
				dict[remainder] = i;
			}
		}
		return false;
    }
};
