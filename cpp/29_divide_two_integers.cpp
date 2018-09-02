#include <iostream>
using namespace std;

// 本题要求实现int的除法，不能使用 / 操作符
// 想到可以使用位运算符来实现，因为除法其实可以转化为减法，而减法都是通过加法来实现的

class Solution {
public:

    long long add(long long a, long long b) {
        long long partialSum, carry;
        do {
            partialSum = a ^ b;
            carry = (a & b) << 1;
            a = partialSum;
            b = carry;
        } while (carry != 0);

        return partialSum;
    }

    long long subtract(long long a, long long b) {
        return add(a, add(~b, 1));
    }

    int divide(int dividend, int divisor) {
        long long x = dividend > 0 ? dividend : add(~dividend, 1);
        long long y = divisor > 0 ? divisor : add(~divisor, 1);

        long long tmp = 0;
        long long result = 0;

        for (int i = 31; i >= 0; --i) {
            tmp = y << i;
            if (x >= tmp) {
                result = add(result, 1LL << i);
                x = subtract(x, tmp);
            }
        }

        if ( (dividend ^ divisor) < 0) {
            result = add(~result, 1);
        }

        if (result > INT_MAX || result < INT_MIN) {
            return INT_MAX;
        } else {
            return (int)result;
        }

    }
};


int main(int argc, char const *argv[]) {
    int quotient = Solution().divide(7, 2);
    printf("quotient is %d\n", quotient);
    return 0;
}



