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

// 给定一个数组，让我们找到其中的peak的idx，所谓peak就是某段区间一直上升的顶点；
// 因为一定存在这个区间，所以其实有三种可能：
// 1> 升序
// 2> 降序
// 3> 正常peak情况
// 查找一般都会想到二分，这里也使用了二分，没一次找到mid后，和mid后面的进行一次比较，假设mid大，则peak在左边，right移动；
// 假设mid小，peak在右边，left移动
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		int left = 0, right = nums.size()-1;

		while (left < right) {
			int mid = left + (right-left)/2;
			if (nums[mid] < nums[mid+1]) {
				left = mid+1;
			} else {
				right = mid;
			}
		}

		return left; // right 
    }
};

