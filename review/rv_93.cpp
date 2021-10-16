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
	void dfs(string s, vector<string>& res, vector<string> ip, int idx) {
		int nsize = s.size();
		if (idx > nsize || ip.size() > 4) { return; }
		if (nsize == idx && ip.size() == 4) {
			auto tmp = ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3];
			res.push_back(tmp);
			return;
		}

		for (int len = 1; len <= 3; ++len) {
			string sub = s.substr(idx, len);
            if (sub.empty() || (sub.size() > 1 && sub[0] == '0') || stoi(sub) > 255) { continue; }
			ip.push_back(sub);
			dfs(s, res, ip, idx+len);
			ip.pop_back();
		}
	}

    vector<string> restoreIpAddresses(string s) {
		if (s.size() > 12) { return {}; }

		vector<string> res;
		dfs(s, res, {}, 0);

		return res;
    }
};
