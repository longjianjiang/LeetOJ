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
	// 前缀和，穷举range，超时；
    bool checkSubarraySum(vector<int>& nums, int k) {
		int nsize = nums.size();
		if (nsize == 0) { return false; }

		vector<int> prefix(nsize+1, 0);
		for (int i = 0; i < nsize; ++i) {
			prefix[i+1] = prefix[i] + nums[i];
		}
		// range(i, j) => [1, 2, 3] => range(0,0-2), range(1, 1-2), range(2,2)
		for (int i = 0; i < nsize; ++i) {
			for (int j = i+1; j < nsize; ++j) {
				int sum = prefix[j+1] - prefix[i];
				if (sum % k == 0) {
					return true;
				}
			}
		}
		return false;
    }

    // range(i, j) % k == 0;  prefix[j+1] - prefix[i] = remainder; 
    bool checkSubarraySum(vector<int>& nums, int k) {
        int nsize = nums.size();
		if (nsize < 2) { return false; }

		vector<int> prefix(nsize+1, 0);
		for (int i = 0; i < nsize; ++i) {
			prefix[i+1] = prefix[i] + nums[i];
		}
		
		unordered_map<int, int> dict;
        dict[0] = -1; // case prefix % k == 0
		for (int i = 0; i < nsize; ++i) {
			int sum = prefix[i+1];
			// if (sum % k == 0) { return true; }
            
			int remainder = sum % k;
			if (dict.find(remainder) != dict.end()) {
                int diff = i - dict[remainder];
                if (diff >= 2) {
                	return true;
                }
            } else {
            	dict[remainder] = i;
            }
		}
		return false;
    }
};
