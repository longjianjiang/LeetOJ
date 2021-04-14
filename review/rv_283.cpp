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

// 将数组中的0移动到最后；不能改变其他数字的相对位置；
// 遍历一次，将非0的从头开始放置，同时记录个数，最后从末尾开始补0；
void moveZeroes(vector<int>& nums) {
	int nsize = nums.size();
	if (nsize <= 1) { return; }

	int pos = 0;
	for (int i = 0; i < nsize; ++i) {
		if (nums[i] != 0) { nums[pos++] = nums[i]; }
	}
	for (int i = pos; i < nsize; ++i) {
		nums[pos] = 0;
	}
}
