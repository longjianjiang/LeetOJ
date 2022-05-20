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
    int threeSumClosest(vector<int>& nums, int target) {
		int nsize = nums.size();
		if (nsize == 0) { return -1; }
		sort(nums.begin(), nums.end());

		int diff = INT_MAX;
		int res = -1;
		auto updateResFunc = [&](int target, int sum) {
			int tmp;
			if (sum < target) {
				tmp = target - sum;
			} else {
				tmp = sum - target;
			}
			if (tmp < diff) {
				diff = tmp;
				res = sum;
			}
		};

		for (int i = 0; i < nsize; ++i) {
			int l = i + 1, r = nsize - 1;
			while (l < r) {
				int sum = nums[i] + nums[l] + nums[r];
				if (sum == target) {
					return sum;
				} else if (sum < target) {
					++l;
					updateResFunc(target, sum);
				} else {
					--r;
					updateResFunc(target, sum);
				}
			}
		}

		return res;
    }
};
