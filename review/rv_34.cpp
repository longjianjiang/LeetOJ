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

/*
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
 */
class Solution {
public:
	int findLeft(vector<int>& arr, int target) {
        int nsize = arr.size();
        int l = 0, r = nsize - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (arr[mid] == target) {
				if (mid == 0 || arr[mid-1] < target) {
					return mid;
				} else {
					r = mid - 1;
				}
			} else if (arr[mid] < target) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return -1;
	}
	int findRight(vector<int>& arr, int target) {
        int nsize = arr.size();
        int l = 0, r = nsize - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (arr[mid] == target) {
				if (mid == nsize - 1 || arr[mid+1] > target) {
					return mid;
				} else {
					l = mid + 1;
				}
			} else if (arr[mid] < target) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
        return -1;
	}
    vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;
		res.push_back(findLeft(nums, target));
		res.push_back(findRight(nums, target));
		return res;
    }

};
