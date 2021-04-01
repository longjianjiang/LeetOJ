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

// 设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
		int nsize = arr.size();
		if (nsize == 0 || k == 0) { return {}; }

		priority_queue<int, vector<int>> maxHeap;

		for (int i = 0; i < k; ++i) { maxHeap.push(arr[i]); }
		for (int i = k; i < nsize; ++i) {
			if (maxHeap.top() > arr[i]) {
				maxHeap.pop();
				maxHeap.push(arr[i]);
			}
		}

		vector<int> res;
		while (!maxHeap.empty()) {
			res.push_back(maxHeap.top());
			maxHeap.pop();
		}

		return res;
    }

    // 3 5 5 1 3
    // right = 3; left = 0;
    // 1 2 5 1 4
    // right = 3; left = 2;
    // 1 2 5 5 4;
    // right = 1; left = 2;
    // 1 2 3 5 4
    int partition(vector<int>& arr ,int left, int right) {
    	int pivot = arr[left];
    	while (left < right) {
    		while (left < right && arr[right] >= pivot) { --right; }
    		if (left < right) { arr[left] = arr[right]; }
    		while (left < right && arr[left] <= pivot) { ++left; }
    		if (left < right) { arr[right] = arr[left]; }
    	}
    	arr[left] = pivot;
    	return left;
    }

    int partition(vector<int>& arr, int left, int right) {
        int nsize = arr.size();
		int pivot = arr[left];
		int pos = left;
		for (int i = pos+1; i < nsize; ++i) {
			if (arr[i] < pivot) {
				++pos;
				if (pos != i) { swap(arr[pos], arr[i]); }
			}
		}
		swap(arr[pos], arr[left]);

		return pos;
	}

	int helper(vector<int>& arr, int k) {
		int nsize = arr.size();

		int left = 0, right = nsize-1;
		while (1) {
			int pos = partition(arr, left, right);
			if (pos == k) {
				return arr[pos];
			} else if (pos > k) {
				right = pos - 1;
			} else {
				left = pos + 1;
			}
		}
	}

	vector<int> smallestK(vector<int>& arr, int k) {
        if (arr.empty() || k == 0) { return {}; }
		vector<int> res;
        int val = helper(arr, k-1);
        cout << val << endl;

		for (int i = 0; i < k; ++i) {
			res.push_back(arr[i]);
		}

		return res;
	}
};
