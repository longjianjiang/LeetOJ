#include <iostream>

using namespace std;

// 给定一个数字让我们判断是否为3的幂，这次就不能从二进制的形式上去解决了，因为没有规律了。
// 所以一个直观的方法就是，循环，每次对3取余，然后将数字除3，直到不是3的倍数，此时判断数字是否为1即可


// 看到另一种方法，不用循环使用对数的换底公式，如果当n为3的幂，那log3n 肯定是一个整数，而logab = log10b / log10a，
// 所以只需要判断(int)(log10b/log10a) == log10b/log10a 即可

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n > 0 && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }

    bool isPowerOfThreeVersionTwo(int n) {
    	return (n > 0) && ( (int)(log10(n) / log10(3)) == (log10(n) / log10(3)) )
    }
};