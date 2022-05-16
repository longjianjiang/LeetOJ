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
private:
		int ipSize = 4;
public:
	// "101023"
	void dfs(string s, vector<string>& res, vector<string> chosen, int idx) {
		int nsize = s.size();
		if (idx > nsize) { return; }
		if (chosen.size() > ipSize) { return; }
		if (idx == nsize && chosen.size() == ipSize) {
			string ip = "";
			for (int i = 0; i < ipSize; ++i) {
				ip += chosen[i];
				if (i < ipSize-1) { ip += "."; }
			}
			res.push_back(ip);
			return;
		}
		for (int len = 1; len <= 3; ++len) {
			string sub = s.substr(idx, len);
			if (sub.empty() || (sub.size() > 1 && sub[0] == '0') || stoi(sub) > 255) { continue; }

			chosen.push_back(sub);
			dfs(s, res, chosen, idx+len);
			chosen.pop_back();
		}
	}

    vector<string> restoreIpAddresses(string s) {
		if (s.size() > 12) { return {}; }

		vector<string> res;
		dfs(s, res, {}, 0);

		return res;
    }
};

template<typename T>
void show_arr_one_dimensional(vector<T> arr) {
	cout << "[";
	for (int i = 0; i < arr.size(); ++i) {
		T num = arr[i];
		if (i == arr.size()-1) {
			cout << num;
		} else {
			cout << num << " ";
		}
	}
	cout << "]\n";
}

template<typename T>
void show_arr_two_dimensional(vector<vector<T>> arr) {
	for (auto v: arr) {
		show_arr_one_dimensional(v);
	}
}

void unit_test() {
	Solution s;
	auto res = s.restoreIpAddresses("101023");
	
	show_arr_one_dimensional(res);
}

int main() {
	unit_test();
	return 0;
}
