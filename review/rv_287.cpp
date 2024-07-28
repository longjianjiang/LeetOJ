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
	// linked list cycle: https://leetcode.cn/problems/find-the-duplicate-number/solutions/58841/287xun-zhao-zhong-fu-shu-by-kirsche
	/*
	 * [1,3,4,2]
	 * idx -> nums[idx]
	 * 0 -> nums[0] = 1;
	 * 1 -> nums[1] = 3;
	 * 2 -> nums[2] = 4;
	 * 3 -> nums[3] = 2;
	 * list => 0 -> f(0):1 -> f(1):3 -> f(3):2 -> f(2):4 -> f(4):null ==> 0->1->3->2->4->null
	 *
	 * [1,3,4,2,2]
	 * list => 0->1->3->2->4->2->4->2->……
	 * 成环了。起点是2；起点也是重复的数字。
	 */
    int findDuplicate(vector<int>& nums) {
    }
};
