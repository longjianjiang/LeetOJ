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

/**
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * 比如n=3时，2*3的矩形块有3种覆盖方法;
 *
 */

// f(n) = f(n-1) + f(n-2)
class Solution {
public:
    int rectCover(int number) {
		if (number <= 0) { return 0; }
		if (number < 3) { return number; }

		int prev = 0, curr = 1, next = 2;
		for (int i = 3; i <= number; ++i) {
			prev = curr;
			curr = next;
			next = prev + curr;
		}
		return next;
    }
};
