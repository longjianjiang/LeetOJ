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
    vector<int> nextGreaterElements(vector<int>& nums) {
		if (nums.empty()) { return {}; }
		
		int nsize = nums.size();
		vector<int> res(nsize, -1);
		stack<int> stk;

		for (int i = 0; i < nsize * 2; ++i) {
			while (!stk.empty() && nums[stk.top()] < nums[i % nsize]) {
				res[stk.top()] = nums[i % nsize];
				stk.pop();
			}
			if (i < nsize) { stk.push(i); }
		}

		return res;
    }
};
