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

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) { return 0; }
        int nsize = nums.size();

        int r = 0;
        int res = 1;
        while (r < nsize) {
            int cnt = 1;
            while (r + 1 < nsize && nums[r+1] > nums[r]) {
                ++r;
                ++cnt;
            }
            if (cnt > 1) {
                res = max(res, cnt);
            } else {
                ++r;
            }
        }
        return res;
    }
};
