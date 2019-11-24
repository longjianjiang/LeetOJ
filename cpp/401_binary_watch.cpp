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

// 一个二进制表，给定亮灯的个数，返回所有可能的时间；

class Solution {
public:
	vector<int> hour = {1, 2, 4, 8}, minute = {1, 2, 4, 8, 16, 32};
	
	void dfs(pair<int, int> time, int num, int idx, vector<string>& res) {
		if (num == 0) {
			if (time.second < 10) {
				res.push_back(to_string(time.first) + ":0" + to_string(time.second));
			} else {
				res.push_back(to_string(time.first) + ":" + to_string(time.second));
			}
			return;
		}

		for (int i = idx; i < hour.size() + minute.size(); ++i) {
			if (i < hour.size()) {
				time.first += hour[i];
				if (time.first < 12) { dfs(time, num-1, i+1, res); }
				time.first -= hour[i];
			} else {
				time.second += minute[i-hour.size()];
				if (time.second < 60) { dfs(time, num-1, i+1, res); }
				time.second -= minute[i-hour.size()];
			}
		}
	}

    vector<string> readBinaryWatch(int num) {
		if (num == 0) { return {"0:00"}; }

		vector<string> res;
		dfs(make_pair(0, 0), num, 0, res);
		return res;
    }
};
