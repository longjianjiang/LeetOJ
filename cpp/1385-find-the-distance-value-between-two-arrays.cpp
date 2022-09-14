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

class Solution {
public:
    int findPeakElement(vector<int>& nums) {        
        int n=(int)nums.size();
        if(n==1 || nums[0]>nums[1]) return 0;
        else if(nums[n-1]>nums[n-2]) return n-1;
        int lo=1, hi=n-2, mid;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(nums[mid]>max(nums[mid-1],nums[mid+1])) return mid;
            else if(nums[mid]<nums[mid-1]) hi=mid-1;
            else lo=mid+1;
        }
        return -1;
    }

	bool helper(vector<int>& arr2, int num, int d) {
        // 3, 2, 1, 0, 1
		int nsize = arr2.size();
		int minLen = INT_MAX;
		if (nsize == 1) {
			minLen = abs(num - arr2[0]);
			return minLen > d;
		}
		int len1 = abs(num - arr2[0]);
		int len2 = abs(num - arr2[1]);
		if (len1 < len2) {
			minLen = len1;
			return minLen > d;
		}
		len1 = abs(num - arr2[nsize-1]);
		len2 = abs(num - arr2[nsize-2]);
		if (len1 < len2) {
			minLen = len1;
			return minLen > d;
		}
		int l = 1, r = nsize-2;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			int lenMid = abs(num - arr2[mid]);
			int lenMidLeft = abs(num - arr2[mid-1]);
			int lenMidRight = abs(num - arr2[mid+1]);
			if (lenMid < min(lenMidLeft, lenMidRight)) {
				minLen = lenMid;
				break;
			} else if (lenMid > lenMidLeft) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if (minLen < INT_MAX && minLen > d) {
			return true;
		}
		return false;
	}
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		sort(arr2.begin(), arr2.end());

        int nsize1 = arr1.size(), nsize2 = arr2.size();
        int res = 0;
        for (int i = 0; i < nsize1; ++i) {
			int num = arr1[i];
			if (helper(arr2, num, d)) { ++res; }
        }

        return res;
    }
};

void unit_test() {
	Solution s;
	vector<int> arr1 = {1, 2, 3, 3, 4, 3};
	vector<int> arr2 = {1, 2, 3, 4, 3, 3};
	cout << s.findPeakElement(arr1) << endl;
	cout << s.findPeakElement(arr2) << endl;
}

int main() {
	unit_test();
	return 0;
}
