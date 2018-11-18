#include <iostream>

using namespace std;

// 本题给定一个数组（非空），让我们找出出现次数超过 size/2 次的元素，而且一定存在。
// 一种直接的思路，先排序，然后遍历数组，找到重复次数超过 size/2 的那个元素返回即可。
// 一种更快的方式，遍历，记录count和当前元素，count为0设置新元素，每次用当前元素和遍历元素比较，对count进行加减，最后返回。

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int size = nums.size() / 2;
        
        int count = 1;
        int cur = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            if (count > size) break;
            
            if (nums[i] == cur) {
                ++count;
                continue;
            } else {
                cur = nums[i];
                count = 1;
            }
        }
        
        return cur;
    }

    int majorityElementVersionTwo(vector<int>& nums) {
    	int cur = 0, count = 0;
    	for (auto num : nums) {
    		if (count == 0) {
    			cur = num;
    			count += 1;
    		} else {
    			num == cur ? count += 1 : count -= 1;
    		}
    	}
    	return cur;
    }
};