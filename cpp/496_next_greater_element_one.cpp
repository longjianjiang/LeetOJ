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

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
// Output: [-1,3,-1]

// 1> 遍历nums1，找到每个元素在nums2的位置，然后往右，寻找是否存在大于的元素；
// 2> 利用单调栈和哈希表，对nums2进行求下一个大的元素，完了遍历nums1，取结果返回；
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		int nsize2 = nums2.size();
		unordered_map<int, int> um;
		stack<int> stk;
		for (int i = 0; i < nsize2; ++i) {
			while (!stk.empty() && stk.top() < nums2[i]) {
				um[stk.top()] = nums2[i]; stk.pop();
			}
			stk.push(nums2[i]);
		}
		
		vector<int> res;
		for (int num: nums1) {
			res.push_back(um.count(num) ? um[num] : -1);
		}

		return res;
    }
};
