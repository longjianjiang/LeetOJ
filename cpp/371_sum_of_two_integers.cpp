#include <iostream>

using namespace std;

// 要求我们实现加法不能用+号，所以只能用位运算符了
// 异或用来求和，与用来求进位

class Solution {
public:
    int getSum(int a, int b) {
    	while (b) {
    		int left = (a & b) << 1;
    		a = a ^ b;
    		b = left;
    	}

    	return a;
    }
};