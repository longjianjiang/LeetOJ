#include <iostream>
#include <unordered_map>
using namespace std;

/*
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

// 利用map，遍历数组每次查看map中有没有target-num的key，有直接返回当前num下表和map中的key即可

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict;
        vector<int> result;

        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (dict.count(target - num)) {
                result.push_back(i);
                result.push_back(dict[target-num]);
                return result;
            }
            dict[num] = i;
        }

        return result;
    }
};