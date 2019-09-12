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
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

class Solution {
public:
	// 遍历找到插入的位置，将插入点后的元素暂存然后挪到插入点后面
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        while (j < n) {
            int added = nums2[j];
            int i;
            for (i = 0; i < m+j; ++i) {
                if (nums1[i] <= added) { continue; }
                
                vector<int> left;
                for (int k = i; k < m+j; ++k) { left.push_back(nums1[k]); }
                nums1[i] = added;
                for (int k = 0; k < left.size(); ++k) { nums1[i+k+1] = left[k]; }
				break;
            }
            
            if (i == m+j) { nums1[m+j] = added; }
            
            ++j;
        }
    }

	// 把nums2作为插入排序插入到nums1中
	void merge_v2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int j = 0;
		while (j < n) {
			int added = nums2[j];
			int i = m+j-1;
			while (i >= 0 && nums1[i] > added) {
				nums1[i+1] = nums1[i];
				i -= 1;
			}
			nums1[i+1] = added;
			++j;
		}
	}

	// 从后面开始，尝试把nums2的元素进行添加到nums1末尾
	void merge_v3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m-1, j = n-1, k = m+n-1;
		while (i >= 0 && j >= 0) {
			if (nums1[i] > nums2[j]) {
				nums1[k--] = nums1[i--];
			} else {
				nums1[k--] = nums2[j--];
			}
		}
		while (j >= 0) { nums1[k--] = nums2[j--]; }
	}
};

void unit_test() {
	Solution s;

	vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	vector<int> nums2 = {2, 5, 6};

	s.merge_v2(nums1, 3, nums2, 3);

	for (auto num : nums1) {
		cout << num << " ";
	}
	cout << endl;
}

int main() {
	unit_test();
	return 0;
}
