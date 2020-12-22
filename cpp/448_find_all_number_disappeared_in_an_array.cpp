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

// 给定数组nums，size为n，数组元素范围是[1, n]，要求返回nums中在[1, n] 未出现的所有元素；
// 题目要求O(1)的空间复杂度（忽略返回的vector），O(n)的时间复杂度；
/*
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/
// 利用数组的取值范围是[1, nsize]，所以取下标进行标记，因为存在重复，一定有元素没有被标记过，那个没有标记的元素的idx+1就是未出现的元素。
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
		if (nums.empty()) { return {}; }
		int nsize = nums.size();
		vector<int> res;

		for (int i = 0; i < nsize; ++i) {
			int idx = abs(nums[i]) - 1;
			nums[idx] = nums[idx] > 0 ? -nums[idx] : nums[idx];
		}
		for (int i = 0; i < nsize; ++i) {
			if (nums[i] > 0) { res.push_back(i+1); }
		}

		return res;
    }
};
