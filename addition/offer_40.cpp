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

// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

// 1> 字典；
// 2> 异或；
class Solution {
public:
    void FindNumsAppearOnce(vector<int> nums,int* num1,int *num2) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
		diff &= -diff;

		vector<int> res(2, 0);
		for (auto num: nums) {
			diff & num ? res[0]^=num : res[1]^=num;
		}
		*num1 = res[0];
		*num2 = res[1];
    }
};
