#include <iostream>

using namespace std;

// 本题给定一个数字让我们判断是否为2的幂
// 既然是2的幂，那么这个数字的二进制里面只有一个1，如果是负数直接是false了

// 还有看到一种方法，将整数减1然后与原来的数进行与，那么如果是2的幂，因为只有一个高位1，那么想与后结果就是0了

class Solution {
public:
    bool isPowerOfTwo(int n) {
    	if (n < 0) return false;

        int count = 0;
        for (int i = 0; i < 31; ++i) {
        	if (count > 1) return false;
        	if (n & (1 << i)) {
        		count += 1;
        	}
        }
        return count == 1;
    }

    bool isPowerOfTwoVersionTwo(int n) {
    	return (n > 0) && !(n & n-1);
    }
};