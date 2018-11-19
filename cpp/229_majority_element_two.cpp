#include <iostream>

using namespace std;

// 和169类似，不过本题让我们找出数组中所有出现次数超过 size/3 次的元素,而且题目要求空间复杂度为O(1);
// 本题需要利用一个叫做`Majority Voting Algorithm`，169的第二种方法其实就是利用了这个算法，其实这个算法不难理解，
// 就是假设一个数为次数最多的，然后遍历，遇到相同的增加count，不同减少count，当count为0时，更换一个备选数，直到结束，这里的前提时数组中存在一个出现次数最多的。

// 而本题需要找出现次数超过 size/3 次的元素，最多存在两个这样的元素。因为假设存在3个次数超过 size/3 次的元素，那么数组的个数肯定大于 3 * size / 3,显然不可能。
// 知道最多存储2个后，我们还是利用上面的算法，进行两次遍历，首先找到两个出现次数最多的元素，第二次遍历则统计这两个元素的出现次数，
// 最后判断这两个元素出现的次数是否超过 size / 3， 因为不像169肯定存在那么一个数，所以需要判断后才插入数组。

// 注意：第一次遍历的时候，需要先判断是否相等而不是count为0，不然可能会将两个相同的数字分到两个数字中，导致结果不对。

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    	vector<int> res;
    	int count1 = 0, count2 = 0;
    	int majority1 = 0, majority2 = 0;

    	for (auto num : nums) {
    		if (num == majority1) {
    			count1 += 1;
    		} else if (num == majority2) {
    			count2 += 1;
    		} else if (count1 == 0) {
    			majority1 = num;
    			count1 += 1;
    		} else if (count2 == 0) {
    			majority2 = num;
    			count2 += 1;
    		} else {
    			count1 -= 1;
    			count2 -= 1;
    		} 
    	}

    	count1 = count2 = 0;

    	for (auto num : nums) {
    		if (num == majority1) {
    			count1 += 1;
    		} else if (num == majority2) {
    			count2 += 1;
    		}
    	}

    	if (count1 > nums.size() / 3) { res.push_back(majority1); }
    	if (count2 > nums.size() / 3) { res.push_back(majority2); }

    	return res;
    }
};