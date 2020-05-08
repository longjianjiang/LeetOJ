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

// 把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

// 1> 暴力，从1开始判断数字是否为丑数，统计个数，当达到index时返回；
// 1 2 3 5
// 2> 算出第n个丑数；
class Solution {
public:
	int getMin(int a, int b, int c) {
		int tmp = min(a, b);
		return min(tmp, c);
	}

    int GetUglyNumber_Solution(int index) {
		vector<int> list = {1};
		vector<int> nums = {2, 3, 5};

		int loc1 = 0, loc2 = 0, loc3 = 0;
		int curIdx = 1;
		while (curIdx < index) {
			int min = getMin(2*list[loc1], 3*list[loc2], 5*list[loc3]);
			list.push_back(min);

			while (2*list[loc1] <= list.back()) { ++loc1; }
			while (3*list[loc2] <= list.back()) { ++loc2; }
			while (5*list[loc3] <= list.back()) { ++loc3; }

			++curIdx;
		}

		return list[index-1];
    }
};
