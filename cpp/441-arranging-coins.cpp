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

class Solution {
public:
	long long getSum(long long n) {
        return n * (n + 1)/2;
    }

    int arrangeCoins(int n) {
        if (n < 1) { return 0; }
        if (n == 1) { return 1; }

        long long res = 0;
        long long l = 1, r = n / 2 + 1;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long sum = getSum(mid);
            if (sum == n) {
                return mid;
            } else if (sum > n) {
                r = mid - 1;
            } else {
                res = mid;
                l = mid + 1;
            }
        }
        return res;
    }
};
