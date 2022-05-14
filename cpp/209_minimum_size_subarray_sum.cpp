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

	int bs(vector<int>& prefix, int sum, int left, int right) {
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (prefix[mid] >= sum) {
				if (mid == 0 || prefix[mid-1] < sum) {
					return mid;
				} else {
					right = mid - 1;
				}
			} else {
				left = mid + 1;
			}
		}
		return -1;
	}

	int minSubArrayLenBS(int s, vector<int>& nums) {
		int nsize = nums.size();
		
		vector<int> prefix(nsize+1, 0);
		for (int i = 0; i < nsize; ++i) {
			if (nums[i] >= s) { return 1; }
			prefix[i+1] = prefix[i] + nums[i];
		}

		int minLen = INT_MAX;
		for (int i = 0; i < nsize; ++i) {
			int pos = bs(prefix, prefix[i]+s, i+1, nsize);
			if (pos == -1) { continue; }
			minLen = min(minLen, pos - i);
		}
		
		return minLen == INT_MAX ? 0 : minLen;
	}
};
