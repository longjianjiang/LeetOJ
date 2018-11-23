#include <iostream>

using namespace std;

// 给定一个数字让我们判断是否为3的幂，这次就不能从二进制的形式上去解决了，因为没有规律了。
// 所以一个直观的方法就是，循环，每次对3取余，然后将数字除3，直到不是3的倍数，此时判断数字是否为1即可

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n > 0 && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};