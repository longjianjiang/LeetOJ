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

// 给定有序数组，删除重复的数字，遍历不断更新，最后返回不重复数字的个数。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) { return nums.size(); }

        int nsize = (int)nums.size();
        int left = 0, right = 1;
        while (right < nsize) {
            if (nums[left] == nums[right]) {
                ++right;
                continue;
            }

            if (right - left == 1) {
                ++left;
                ++right;
            } else {
                swap(nums[++left], nums[right++]);
            }
        }

        return left+1;
    }

    int removeDuplicates_1(vector<int>& nums) {
        if (nums.size() <= 1) { return nums.size(); }
        
		int nsize = (int)nums.size();
        int cursor = 0, cnt = 0;
        while (cursor < nsize) {
            int num = nums[cursor++];
            
            while (cursor < nsize && nums[cursor] == num) { ++cursor; }
            
            nums[cnt++] = num;
        }
        
        return cnt;
    }
};


void unit_test() {
	Solution s;

	vector<int> nums = {1, 1, 2};
	int cnt = s.removeDuplicates_1(nums);

	for (auto num : nums) {
		cout << num << endl;
	}
}

int main() {
	unit_test();
	return 0;
}
