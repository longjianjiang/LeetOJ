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

// 给定数组和sum，要求返回最短的子数组和大于sum的长度；
// 1> two pinter
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) { return 0; }
		int left = 0, right = 0, sum = 0;
		int cnt = INT_MAX;
		while (right < nums.size()) {
			sum += nums[right++];
			while (sum >= s) {
				cnt = min(cnt, right-left);
				sum -= nums[left++];
			}
		}

		return cnt == INT_MAX ? 0 : cnt;
	}
};
