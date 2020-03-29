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

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// 找出序列中第一个是坏的版本，当某个版本是坏的那么这个版本后面所有的版本都是坏的。
// 二分查找即可。
class Solution {
public:
    int firstBadVersion(int n) {
		int left = 1, right = n;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (isBadVersion(mid)) { 
				bool conditionOne = mid == 0;
				bool conditionTwo = isBadVersion(mid-1) == false;
				if (conditionOne || conditionTwo) {
					return mid;
				} else {
					right = mid-1;
				}
			} else {
				left = mid+1;
			}
		}
		return -1;
    }
};
