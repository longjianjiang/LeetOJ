// 给定数组和k，判断是否存储i,j; nums[i] == nums[j], 同时i，j间距不超过k
// 使用map即可
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty() || k < 1) { return false; }
        
        unordered_map<int, int> dict;
        
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (dict.find(num) != dict.end()) {
                int diff = i - dict[num];
                if (diff <= k) { return true; }
            } 
            dict[num] = i;
        }
        
        return false;
    }
};
