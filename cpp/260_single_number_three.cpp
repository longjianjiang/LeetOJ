#include <iostream>
#include <vector>

using namespace std;

// 本题和126很像，只是本题只出现一次的数字有两个
// 思路还是位运算，如果我们将这两个只出现一次的数字区分开来，其实也就达到题目的要求了
// 首先我们求出数组中所有元素异或的结果，其实就是两个只出现一次数字异或的值，此时我们找到一位为1的，将其他位置为0，比如我们就找从低位开始第一个为1的位；
// 得到上述的diff后，我们继续遍历数组，将数字与diff进行与运算，因为我们选取的是异或结果为1的位，所以那两个只出现一次的数字与diff与运算，肯定一个为0一个为1；
// 又因为其他的数字都出现两次，所以建立一个数组两个元素，初始化为0，将其与数组中的数字进行与运算，最后两个只出现一次的数字则被放在数组中了。

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> res(2, 0);
        for(auto num : nums) {
        	num & diff ? res[0] ^= num : res[1] ^= num;
        }
        return res;
    }
};