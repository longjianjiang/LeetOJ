#include <iostream>

using namespace std;

// 给定一个32位无符号整数，要求将其二进制形式反转，返回整形数值
// 直接将给定的n的二进制形式，从低位开始遍历每一位，每次将res左移一位，如果是1，则加1，也就是做|运算一次

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        auto bits = sizeof(n) * 8;
        uint32_t res = 0;
        for(int i = 0; i < bits; ++i) {
            res = (res << 1) | (n & 1);
            n >>= 1;

            //或者将上面两步合成一步
            // res = (res << 1) + (n >> i & 1);
        }

        return res;
    }
};