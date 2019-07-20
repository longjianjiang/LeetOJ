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

// 给定数组和k，要求返回pair(i, j), i，j在数组范围内，并且两者对应的差值等于k，返回pair的数量，不能重复。
// 遍历即可
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());

        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) { continue; }

            int l = i, r = i+1;
            while (r < nums.size()) {
                int diff = abs(nums[r]-nums[l]);
                if (diff >= k) {
                    if (diff == k) { res += 1; }
                    break;
                } else {
                    r += 1;
                }
            }
        }

        return res;
    }
};

void unit_test() {
	Solution s;

    vector<int> nums = {1, 1, 3, 4, 5};
    assert(s.findPairs(nums, 2) == 2);
}

int main() {
	unit_test();
	return 0;
}
