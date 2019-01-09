#include <iostream>

using namespace std;

// 给定一个数字让我们判断是否为4的幂
// 思路和2的幂那题类似，依然从二进制形式入手，首先既然是4的幂，依然二进制中只能有一个1，另外因为是4的幂，所以1的位置是以2的等差数列

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 0) return false;
        int count = 0;
        bool flag = false;
        for (int i = 0; i < 31; ++i) {
            if (num & (1 << i)) {
                count += 1;
                if (i % 2 == 0) flag = true;
            }
        }
        return count == 1 && flag;
    }
};