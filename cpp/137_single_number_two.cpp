#include <iostream>

using namespace std;

// 本题和136类似，不过本题重复的次数为3，让我们找出那个不重复的数字
// 所以此时就不能使用异或了，但是依然可以从二进制的形式来看，我们统计数组中数字每一位的和，将其对3取余
// 将余数依次填充到res中返回即可

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; ++i) {
            int mask = 1 << i;
            int count = 0;
            for (auto num : nums) {
                if (mask & num) {
                    count += 1;
                }
            }

            res |= (count % 3) << i;
        }

        return res;
    }
};