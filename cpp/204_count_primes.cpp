#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 给定n，返回从1-n中质数的个数；
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// 遍历，从质数2开始，将2的倍数进行标记为非质数；然后找到下一个是质数的，继续进行倍数标记；
class Solution {
public:
    int countPrimes(int n) {
		if (n <= 1) { return 0; }

		vector<int> arr(n, 0);
		int res = 0;
		for (int i = 2; i < n; ++i) {
			if (arr[i] == 0) {
				++res;
				int j = 2;
				while (i*j < n) {
					arr[i*j] = 1;
					++j;
				}
			}
		}
		return res;
    }
};
