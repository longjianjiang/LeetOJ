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
 给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m + n) 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。
 
 求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。
 
 输入:
 nums1 = [3, 4, 6, 5]
 nums2 = [9, 1, 2, 5, 8, 3]
 k = 5
 输出:
 [9, 8, 6, 5, 3]
 */

// [9, 3, 4, 6, 8]
// 6 9583    ->    96583
// 65 983    ->    98653
// 465 98    ->     98465
// 3465 9    ->     93465
// 0 91258    ->    91258

// 首先求最大的数，那么倒序一定是最大的。所以其实可以使用到单调栈，来求最大。
// 这里有两个数组，k位，所以其实就是对两个数组求最大，然后进行合并。
// 最后一个问题就是k的分配。
// 其实复杂的问题，一般是需要用到不止一种算法。此时需要我们对每个问题足够熟悉，这样才能举一反三。
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int nsize1 = nums1.size(), nsize2 = nums2.size();
        vector<int> res;
        
        for (int i =0; i <= k; ++i) {
            vector<int> one = findMax(nums1, nsize1-i);
            vector<int> two = findMax(nums2, nsize2-k+i);
            vector<int> mergeOne = mergeArr(one, two);
            vector<int> mergeTwo = mergeArr(two, one);

            vector<int> bigger = compareNums(mergeOne, mergeTwo);
            res = compareNums(res, bigger);
        }
        
        return res;
    }
    
    /// 移除k位，返回最大的结果
    vector<int> findMax(vector<int>& nums, int k) {
        if (nums.empty()) { return nums; }
        int nsize = nums.size();
        if (k == 0) { return nums; }
        if (k >= nsize) { return {}; }
        
        stack<int> stk;
        
        for (int i = 0; i < nsize; ++i) {
            while (!stk.empty() && nums[i] > nums[stk.top()] && k > 0) {
                stk.pop();
                --k;
            }
            stk.push(i);
        }
        while (k > 0) {
            stk.pop();
            --k;
        }
        
        vector<int> res;
        while (!stk.empty()) {
            res.push_back(nums[stk.top()]);
            stk.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
    
    /// 合并数组，使合并结果最大
    vector<int> mergeArr(vector<int>& nums1, vector<int> nums2) {
        int p = 0, q = 0;
        int pos = 0;
        int nsize1 = nums1.size(), nsize2 = nums2.size();
        vector<int> res;
        
        while (p < nsize1 && q < nsize2) {
            if (nums1[p] > nums2[q]) {
                res.push_back(nums1[p++]);
            } else {
                res.push_back(nums2[q++]);
            }
        }
        
        while (p < nsize1) {
            res.push_back(nums1[p++]);
        }
        while (q < nsize2) {
            res.push_back(nums2[q++]);
        }
        return res;
    }
    
    vector<int> compareNums(vector<int>& nums1, vector<int>& nums2) {
        int nsize1 = nums1.size(), nsize2 = nums2.size();
        if (nsize1 == nsize2) {
            for (int i = 0; i < nsize1; ++i) {
                if (nums1[i] == nums2[i]) { continue; }
                return nums1[i] > nums2[i] ? nums1 : nums2;
            }
        }
        return nsize1 > nsize2 ? nums1 : nums2;
    }
};

void show_arr_one_dimensional(vector<int> arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); ++i) {
        int num = arr[i];
        if (i == arr.size()-1) {
            cout << num;
        } else {
            cout << num << " ";
        }
    }
    cout << "]\n";
}

void show_arr_two_dimensional(vector<vector<int>> arr) {
    for (auto v: arr) {
        show_arr_one_dimensional(v);
    }
}

void unit_test() {
    Solution s;
    
    vector<int> nums1 = {3, 4, 6, 5};
    vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    vector<int> res = s.maxNumber(nums1, nums2, 5);
    show_arr_one_dimensional(res);

    nums1 = {6, 7}; nums2 = {6, 0, 4};
    res = s.maxNumber(nums1, nums2, 5);
    show_arr_one_dimensional(res);

    nums1 = {3, 9}; nums2 = {8, 9};
    res = s.maxNumber(nums1, nums2, 3);
    show_arr_one_dimensional(res);

}

int main() {
    unit_test();
    return 0;
}



