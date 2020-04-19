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

// 给定n，返回二进制形式中1的个数；
class Solution {
public:
     int  NumberOf1(int n) {
		 int res = n & 1;
		 // 逻辑右移，否则负数的时候会死循环；
		 while (n = (unsigned)n << 1) {
			 res += n & 1;
		 }
		 return res;
     }

	 // 上面的方式思路是每次和1进行&运算，然后将num进行右移；
	 // 另一种思路是每次和a进行&运算，然后将a进行左移，需要处理一下移动的位数；
	 int NumberOf1_2(int n) {
		 int a = 1;
		 int res = 0;
		 for (int i = 1; i <= 32; ++i) {
			 if ((n & a) != 0) {
				 ++res;
			 }
			 a <<= 1;
		 }
		 return res;
	 }

	 // n & (n-1) => 将最低位的1置为0
	 int NumberOf1_3(int n) {
		 int res = 0;
		 while (n != 0) {
			 ++res;
			 n &= (n-1);
		 }
		 return res;
	 }
};
