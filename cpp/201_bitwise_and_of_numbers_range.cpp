#include <iostream>

using namespace std;

// 要求我们将m-n之间所有的数字进行与运算，将结果返回
// 如果我们直接遍历进行与运算，会超时
// 所以需要我们从二进制的形式上入手，看看有什么规律，从而降低运行时间
// 其实我们观察连续的二进制数字，其实他们与运算的结果就是最大值和最小值从最高位开始与是否为1，当某位不是1时，此时即可返回了

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        for(int i = 31; i >= 0; --i) {
            int high = m & (1 << i);
            int low = n & (1 << i);

            if (high == 0 && low == 0) {
                continue;
            }

            if (high & low) {
                res |= (1 << i);
            } else {
                break;
            }
        }
        return res;
    }

    // 通过右移的方式找最高位
    int rangeBitwiseAndVersionTwo(int m, int n) {
        int offset = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            offset += 1;
        }
        return m << offset;
    }
};