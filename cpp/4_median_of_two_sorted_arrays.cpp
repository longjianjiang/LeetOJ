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

// 给定两个有序数组，返回两个数组组合后的中位数。
// 可以化解成在两个有序数组中寻找第k个元素：
// 1. 当某个数组为空，直接返回[k-1];
// 2. 当k=1，返回min(nums1[0], nums2[0]);
// 3. 二分，减小k同时截取数组；
class Solution {
public:
	int findkth(vector<int> nums1, vector<int> nums2, int k) {
		if (nums1.empty()) { return nums2[k-1]; }
		if (nums2.empty()) { return nums1[k-1]; }
		if (k == 1) { return min(nums1[0], nums2[0]); }

	    int m = (int)nums1.size(), n = (int)nums2.size();
		int i = min(m, k/2), j = min(n, k/2);

		if (nums1[i-1] > nums2[j-1]) {
			return findkth(nums1, vector<int>(nums2.begin()+j, nums2.end()), k-j);
		} else {
			return findkth(vector<int>(nums1.begin()+i, nums1.end()), nums2, k-i);
		}
	}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	    int m = (int)nums1.size(), n = (int)nums2.size();
		int i = (m+n+1) / 2, j = (m+n+2)/2;

		return (findkth(nums1, nums2, i) + findkth(nums1, nums2, j)) / 2.0;
    }
};

/*
# 该方法的核心是将原问题转变成一个寻找第k小数的问题（假设两个原序列升序排列），这样中位数实际上是第(m+n)/2小的数。所以只要解决了第k小数的
# 问题，原问题也得以解决。
#
# 首先假设数组A和B的元素个数都大于k/2，我们比较A[k/2-1]和B[k/2-1]两个元素，这两个元素分别表示A的第k/2小的元素和B的第k/2小的元素。这两
# 个元素比较共有三种情况：>、<和=。如果A[k/2-1]<B[k/2-1]，这表示A[0]到A[k/2-1]的元素都在A和B合并之后的前k小的元素中。换句话说，A[k/2-1]不
# 可能大于两数组合并之后的第k小值，所以我们可以将其抛弃。
#
# 当A[k/2-1]=B[k/2-1]时，我们已经找到了第k小的数，也即这个相等的元素，我们将其记为m。由于在A和B中分别有k/2-1个元素小于m，所以m即是第k小
# 的数。(如果k为奇数，则m不是中位数。这里是进行了理想化考虑，在实际代码中略有不同，是先求k/2，然后利用k-k/2获得另一个数。)
#
# 通过上面的分析，我们即可以采用递归的方式实现寻找第k小的数。此外我们还需要考虑几个边界条件：
#
# 如果A或者B为空，则直接返回B[k-1]或者A[k-1]；
# 如果k为1，我们只需要返回A[0]和B[0]中的较小值；
# 如果A[k/2-1]=B[k/2-1]，返回其中一个；

   def findKth(self,A,B,k):
        #always assume that m is equal or smaller than n
        if len(A) > len(B):
            return self.findKth(B,A,k)

        if len(A) == 0:
            return B[k - 1]
        if k == 0 or k == 1:
            return min(A[0],B[0])

        #divide k into two parts
        pa = min(len(A),k / 2)
        pb = k - pa
        if A[pa - 1] < B[pb - 1]:
            return self.findKth(A[pa :],B,k - pa)
        elif A[pa - 1] > B[pb - 1]:
            return self.findKth(A,B[pb :],k - pb)
        else:
            return A[pa - 1]
*/

// [1, 2] [1, 4] [1, 1, 2, 4]
// k = 2, k = 3
// pa = 1, pb = 1; => 1
// pa = 1, pb = 2; => 2

// [2], [1, 4] [1, 2, 4]
// k = 2
// pa = 1, pb = 1

// [2], [4] [2, 4]
// k = 1
// pa = 0, pb = 1
void unit_test() {
	Solution s;
}

int main() {
	unit_test();
	return 0;
}
