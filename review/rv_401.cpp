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
	vector<int> hours = {1, 2, 4, 8};
	vector<int> minutes = {1, 2, 4, 8, 16, 32};

	void dfs(int num, int hour, int minute, int idx, vector<string>& res) {
		if (num == 0) {
			if (minute < 10) {
				res.push_back(to_string(hour) + ":0" + to_string(minute));
			} else {
				res.push_back(to_string(hour) + ":" + to_string(minute));
			}
			return;
		}
		for (int i = idx; i < hours.size()+minutes.size(); ++i) {
			if (i < hours.size()) {
				int h = hours[i];
				hour += h;
				if (hour < 12) { dfs(num-1, hour, minute, i+1, res); }
				hour -= h;
			} else {
				int m = minutes[i-hours.size()];
				minute += m;
				if (minute < 60) { dfs(num-1, hour, minute, i+1, res); }
				minute -= m;
			}
		}
	}
	
    vector<string> readBinaryWatch(int num) {
		if (num == 0) { return {"0:00"}; }

		vector<string> res;
		dfs(num, 0, 0, 0, res);
		return res;
    }
};
