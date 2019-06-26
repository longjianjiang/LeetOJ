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
    int trap(vector<int>& height) {
        if (height.size() <= 2) { return 0; }

        int idx = 0;
        while(height[idx] == 0) {
            idx++;
        }

		int resVal = 0;
		stack<int> s;
		while (idx < height.size()) {
			int h = height[idx];
			if (s.empty() || h <= height[s.top()]) {
				s.push(idx++);
			} else {
                int mid = height[s.top()]; s.pop();
                if (s.empty()) { continue; }
                int trap = (min(height[s.top()], h)-mid) * (idx - s.top() - 1);
                resVal += trap;
            }
		}

		return resVal;
    }
};

void unit_test() {
	Solution s;

	vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
	assert(s.trap(heights) == 6);
}

int main() {
	unit_test();
	return 0;
}
