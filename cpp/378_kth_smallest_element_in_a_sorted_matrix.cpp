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

// 给定一个n*n的矩阵，每行每列都是升序的，给定k，返回第k小的元素；
// 1> 使用最大堆；
// 2> bs；

class Solution {
public:
	int kthSmallest_heap(vector<vector<int>>& matrix, int k) {
		priority_queue<int> q;
		int n = matrix.size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				q.push(matrix[i][j]);
				if (q.size() > k) { q.pop(); }
			}
		}
		return q.top();
	}

    int kthSmallest(vector<vector<int>>& matrix, int k) {
		int left = matrix[0][0], right = matrix.back().back();
		while (left < right) {
			int mid = left + (right-left)/2; int cnt = 0;
			for (int i = 0; i < matrix.size(); ++i) {
				cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
			}
			if (cnt < k) {
				left = mid+1;
			} else {
				right = mid;
			}
		}
		return left;
    }

	int kthSmallest_optimize(vector<vector<int>>& matrix, int k) {
		int left = matrix[0][0], right = matrix.back().back();
		while (left < right) {
			int mid = left + (right-left)/2; int cnt = 0;
			cnt = find_pos(matrix, mid);
			if (cnt < k) {
				left = mid+1;
			} else {
				right = mid;
			}
		}
		return left;
	}

	int find_pos(vector<vector<int>>& matrix, int target) {
		int n = matrix.size(), cnt = 0;
		int i = n-1, j = 0;
		while (i >= 0 && j < n) {
			if (matrix[i][j] <= target) {
				cnt += (i+1);
				++j;
			} else {
				--i;
			}
		}
		return cnt;
	}
};
