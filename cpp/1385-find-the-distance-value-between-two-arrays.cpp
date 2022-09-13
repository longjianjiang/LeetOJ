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

        // int left = 0, right = nums.size()-1;

        // while (left < right) {
        //     int mid = left + (right-left)/2;
        //     if (nums[mid] < nums[mid+1]) {
        //         left = mid+1;
        //     } else {
        //         right = mid;
        //     }
        // }

        // return left; // right 
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		sort(arr2.begin(), arr2.end());

        int nsize1 = arr1.size(), nsize2 = arr2.size();
        int res = 0;
        // 3, 2, 1, 0, 1
        for (int i = 0; i < nsize1; ++i) {
            vector<int> tmp;
            for (int j = 0; j < nsize2; ++j) {
                tmp.push_back(abs(arr1[i] - arr2[j]));
            }
            int num = arr1[i];
            int l = 0, r = nsize2-1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                int lenMid = abs(num - arr2[mid]);
                int lenRight = abs(num - arr2[mid+1]);
                if (lenMid > lenRight) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            int minLen = abs(num - arr2[l]);
            if (minLen > d) {
                ++res;
                cout << "i = " << i << ", num = " << arr1[i] << endl;
            }
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
