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
    int maxArea(vector<int>& height) {
		int nsize = height.size();
        int l = 0, r = nsize - 1;

        int res = 0;
        while (l <= r) {
            int h = min(height[l], height[r]);
            int w = r - l;
            int tmpArea = w * h;
            res = max(res, tmpArea);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return res;
    }
};
