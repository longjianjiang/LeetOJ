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
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/

class Solution {
public:
	// union find.
	// union : consecutive sequence;
	// find : num, num+1, union(num, num+1); um[num+1] = num;
	int longestConsecutiveUnionFind(vector<int>& nums) {
		unordered_map<int, int> um;
		unordered_map<int, int> cnt;
		for (auto num : nums) {
			um[num] = num;
			cnt[num] = 1;
		}

		auto findFunc = [&](int i) {
			while (i != um[i]) {
				um[i] = um[um[i]];
				i = um[i];
			}
			return i;
		};
		
		// 100 4 200 1 3 2
		// 1   1  1  1 2 1
		auto unionFunc = [&](int i, int j) {
			int p = findFunc(i), q = findFunc(j);
			if (p != q) {
				um[q] = p;
				cnt[p] += cnt[q];
			}
		};
		
		for (auto num : nums) {
			if (um.find(num+1) != um.end()) {
				unionFunc(num, num+1);
			}
		}

		int res = 0;
		for (auto x : cnt) {
			res = max(res, x.second);
		}
		return res;
	}

    int longestConsecutive(vector<int>& nums) {
		unordered_set<int> us;
		for (auto num : nums) {
			us.insert(num);
		}

		int res = 0;
		for (auto num : nums) {
			if (us.find(num - 1) == us.end()) {
				int first = num;
				int cnt = 1;
				while (us.find(first + 1) != us.end()) {
					++first;
					++cnt;
				}
				res = max(res, cnt);
			}
		}

		return res;
    }
};

void unit_test() {
	Solution s;

	vector<int> nums = {100, 4, 200, 2, 1, 3};
	cout << s.longestConsecutiveUnionFind(nums) << endl;
}

int main() {
	unit_test();
	return 0;
}
