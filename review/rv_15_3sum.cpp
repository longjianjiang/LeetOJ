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
    vector<vector<int>> threeSum(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize < 3) { return {}; }

		sort(nums.begin(), nums.end());

		// [-4, -1, -1, 0, 1, 2]
		vector<vector<int>> res;
		for (int i = 0; i < nsize; ++i) {
			if (nums[i] > 0) { break; } 
			int l = i + 1, r = nsize - 1;
			while (l < r) {
				int sum = nums[i] + nums[l] + nums[r];
				if (sum < 0) {
					++l;
				} else if (sum > 0) {
					--r;
				} else {
					vector<int> triplet = {nums[i], nums[l], nums[r]};
					res.push_back(triplet);
					
					while (l + 1 < r && nums[l] == nums[l+1]) {
						++l;
					}
					while (r - 1 > l && nums[r] == nums[r-1]) {
						--r;
					}
					++l;
					--r;
				}
			}
			while (i + 1 < nsize && nums[i] == nums[i+1]) {
				++i;
			}
		}

		return res;
    }
};
