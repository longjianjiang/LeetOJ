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
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		        sort(arr2.begin(), arr2.end());

        int nsize1 = arr1.size(), nsize2 = arr2.size();
        int res = 0;
        // 3, 2, 1, 0, 1
        for (int i = 0; i < nsize1; ++i) {
            vector<int> tmp;
            for (int j = 0; j < nsize2; ++j) {
                tmp.push_back(abs(arr1[i] - arr2[j]));
            }
            int num = arr1[i];
            int l = 0, r = nsize2-1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                int lenMid = abs(num - arr2[mid]);
                int lenRight = abs(num - arr2[mid+1]);
                if (lenMid > lenRight) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            int minLen = abs(num - arr2[l]);
            if (minLen > d) {
                ++res;
                cout << "i = " << i << ", num = " << arr1[i] << endl;
            }
        }

        return res;
    }
};
