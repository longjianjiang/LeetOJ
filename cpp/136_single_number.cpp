#include <iostream>

using namespace std;

// 题目中说给定一个数组，里面的数字除了一个是没有重复的其他的都是出现了两次，让我们返回这个不重复的
// 利用异或运算符，依次对数组中的所有数字进行异或，最后结果就是那个不重复的数字

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            res ^= nums[i];
        }
        return res;
    }
};