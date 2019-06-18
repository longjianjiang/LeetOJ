// 给定数组和两个限制，k 元素的距离限制，t 元素值的间隔限制
// 数组中是否满足nums[i]和nums[j]值间隔不超过t，i和j距离间隔不超过k，存在一个返回true即可
// 使用map来存键值关系，首先保证map里存的元素的下标范围不超过k，从map中第一个大于等于num-t的键值，此时距离num是最小的；
// 寻找需要使用`lower_bound`方法，二分效率更高，遍历寻找会超时。
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (nums.empty() || k < 1) { return false; }
    
		map<long long, int> dict;
		int pointer = 0;
		for (int i = 0; i < nums.size(); ++i) {
			// dict elements distance at most k
			if (i - pointer > k) {
				dict.erase(nums[pointer]);
				pointer++;
			}
			int num = nums[i];
			auto j = dict.lower_bound((long long)num-t);
			if (j != dict.end() && abs(j->first - num) <= t) { return true; }
			dict[num] = i;
		}

		return false;
    }
};
