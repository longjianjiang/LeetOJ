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
	vector<int> nextGreaterElementsV2(vector<int>& nums) {
        int nsize = nums.size();
        vector<int> res(nsize, -1);
        stack<int> stk;

        for (int i = 0; i < nsize * 2; ++i) {
            int tmp = nums[i % nsize];
            while (stk.empty() == false && nums[stk.top() % nsize] < tmp) {
                int idx = stk.top();
                res[idx % nsize] = tmp;
                stk.pop();
            }
            stk.push(i % nsize);
        }

        return res;
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
		if (nums.empty()) { return {}; }
		int nsize = nums.size();
		vector<int> res(nsize, -1);
		stack<int> stk;

		// [1, 2, 1]
		for (int i = 0; i < nsize * 2; ++i) {
			int num = nums[i % nsize];
			while (!stk.empty() && num > nums[stk.top()]) {
				res[stk.top()] = num;
				stk.pop();
			}
			if (i < nsize) {
				stk.push(i);
			}
		}
		return res;
    }
};

void unit_test() {
	Solution s;
}

int main() {
	unit_test();
	return 0;
}
