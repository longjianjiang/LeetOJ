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

// 给定一个mountain数组，就是一定存在某个区间中间最大两边小于中间值，让我们返回这个最大值的idx；
// 一般查找都可以想到二分，这里的二分是每次mid和左右进行比较

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0, right = A.size()-1;

		while (left <= right) {
			int mid = left + (right-left)/2;

			if ((mid-1) < 0 || (mid+1) > A.size()-1) { break; }
			if (A[mid] > A[mid-1] && A[mid] > A[mid+1]) {
				return mid;
			} else if (A[mid] < A[mid-1]) {
				right = mid;
			} else {
				left = mid;
			}
		}

		return -1;
    }
};
