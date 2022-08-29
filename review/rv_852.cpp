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
    int peakIndexInMountainArray(vector<int>& arr) {
		/*
        int nsize = arr.size();
        int idx = 0;
        while (idx+1 < nsize) {
            if (arr[idx+1] < arr[idx]) {
                break;
            }
            ++idx;
        }
        return idx;
		*/
        
        int nsize = arr.size();
        int l = 0, r = nsize - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mid - 1 < 0 || mid + 1 >= nsize) { break; }
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
                return mid;
            } else if (arr[mid] < arr[mid-1]) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return -1;
    }
};
