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
假设你有两个数组，一个长一个短，短的元素均不相同。找到长数组中包含短数组所有的元素的最短子数组，其出现顺序无关紧要。

返回最短子数组的左端点和右端点，如有多个满足条件的子数组，返回左端点最小的一个。若不存在，返回空数组。

输入:
big = [7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7]
small = [1,5,9]
输出: [7,10]
*/

class Solution {
public:
	// 最初的思路是同时确定left和right。
	// 提交了只过了29 / 42 个通过测试用例。
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        if (big.empty() || small.empty()) { return {}; }

        int nsize = big.size();
        int left = 0, right = 0;
        vector<int> arr;

        unordered_set<int> us1;
        unordered_set<int> us2;
        for (auto num : small) { us2.insert(num); }

        while (right < nsize) {
            int tmp = big[right];
            if (us2.find(tmp) == us2.end()) {
                if (us1.empty()) { ++left; }
            } else {
                us1.insert(tmp);
                if (us1.size() == us2.size()) {
                    if (arr.empty()) {
                        arr.push_back(left);
                        arr.push_back(right);
                    } else {
                        int oldLen = arr[1] - arr[0] + 1;
                        int newLen = right - left + 1;
                        if (newLen < oldLen) {
                            arr.clear();
                            arr.push_back(left);
                            arr.push_back(right);
                        }
                    }
                    us1.erase(big[left++]);
                }
            }
            ++right;
        }
        return arr;
    }

	// 固定left为开头，首先移动right直到满足条件。
	// 此时尝试移动left，看是否满足条件，同时更新条件。
	// 参考：https://leetcode-cn.com/problems/shortest-supersequence-lcci/solution/xiang-xi-tu-jie-hua-dong-chuang-kou-chao-qi7g/
	vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
		int nsize = big.size();
		int minLen = INT_MAX;
		unordered_map<int, int> map;
		int cnt = 0;
		int left = 0, right = 0;
		vector<int> res;

		for (auto num : small) {
			++map[num];
			++cnt;
		}
		while (right < nsize) {
			int tmp = big[right];	
			if (map.find(tmp) != map.end() && --map[tmp] >= 0) { --cnt;  }
			while (cnt == 0) {
				if (right - left < minLen) {
					res = {left, right};
					minLen = right - left;
				}
				if (map.find(big[left]) != map.end() && ++map[big[left]] > 0) { ++cnt;  }
				++left;
			}
			++right;
		}

		return res;
	}
};
