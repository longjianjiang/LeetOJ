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
 输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
 输出: [-1,3,-1]
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		//nums2.push_back(INT_MAX);
        int nsize2 = nums2.size();
		stack<int> stk;
		unordered_map<int, int> dict;
		for (int i = 0; i < nsize2; ++i) {
			int num = nums2[i];
			while (!stk.empty() && num > stk.top()) {
				dict[stk.top()] = num;
				stk.pop();
			}
			stk.push(num);
		}

		vector<int> res;
		for (auto num : nums1) {
			if (dict.find(num) != dict.end()) {
				res.push_back(dict[num]);
			} else {
				res.push_back(-1);
			}
		}
		return res;
    }
};
