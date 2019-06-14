// 给定一个数组，判断是否有元素重复
// 使用一个set即可
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
   		if (nums.empty()) { return false; }     

		unordered_set<int> us;
		for (auto num: nums) {
			if (us.find(num) != us.end()) {
				return true;
			} 
			us.insert(num);
		}

		return false;
    }
};
