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

// 给定num，判断是否为某个整数的平方；
// 二分查找，使用除法来判断，可以防止越界问题；
class Solution {
public:
    bool isPerfectSquare(int num) {
		if (num < 1) { return false; }
		if (num == 1) { return true; }
		int l = 1, r = num/2;
		double mid = 0;
		while (l <= r) {
			mid = l + (r - l) / 2;
			if (num/mid == mid) {
				return true;
			} else if (num/mid > mid) {
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
		return false;
    }
};
