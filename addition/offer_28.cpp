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

// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0

// 1> 遍历一次，用map记录下次数，然后遍历map，次数大于一半长度的返回，否则返回0；
// 2> 遍历两次次，记录当前数字和出现次数，因为大于一半，所以最后剩下的就是那个数字，第二次统计该数的次数，大于一半返回；
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
		int res = -1, times = 0;
		int nsize = numbers.size();
		for (auto num: numbers) {
			if (num == res) {
				++times;
			} else {
				if (times > 0) {
					--times;
				} else {
					res = num;
					++times;
				}
			}
		}
		times = 0;
		for (auto num: numbers) {
			if (num == res) { ++times; }
		}
		return (times > nsize / 2) ? res : 0;
    }
};
