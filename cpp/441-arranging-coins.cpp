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
    int getSum(int n) {
        if (n <= 1) { return n; }

        int i = 1; int j = n;
        int sum = 0;
        while (i < j) {
            sum += (i + j);
            ++i; --j;
        }
        if (i == j) { sum += j; }
        return sum;
    }

    int arrangeCoins(int n) {
        if (n < 1) { return 0; }
        if (n == 1) { return 1; }
        // 2; 1, 2
        // 3; 1, 2

        // 4; 1, 3
        // 5; 1, 3

        int l = 1, r = n / 2 + 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int sum = getSum(l);
            if (sum >= n) {
                return mid;
            } else {
                l++;
            }
        }
        return -1;
    }
};