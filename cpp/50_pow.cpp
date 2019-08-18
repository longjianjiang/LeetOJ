#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 计算x的n次方
// 二分的思想来求，时间复杂度降到logN;
// 10	2
// 5	4
// 2	16
// 1	256
// 二分一下 2^10 = 2^2 * 2^8 = 4 * 256 = 1024
class Solution {
public:
    double myPow(double x, int n) {
        bool flag = n > 0;

        double res = 1.0;
        double tmp = x;
        long long val = abs((long long)n); // 这里取绝对值需要类型转下，2^31 int 存储不下；

        while (val) {
            if (val & 1) { res *= tmp; }
            tmp *= tmp;
            val >>= 1;
        }

        if (!flag) { return 1 / res; }
        return res;
    }
};
