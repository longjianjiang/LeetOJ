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

// 将字符串字母组成相同的存入数组，返回一个二维数组
/*
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

class Solution {
public:
	bool is_anagram(string one, string two) {
		if (one.size() != two.size()) { return false; }

		unordered_map<char, int> um;
		for (char ch : one) {
			um[ch] += 1;
		}
		for (char ch : two) {
            um[ch] -= 1;
		}
        for (char ch : one) {
            if (um[ch] != 0) { return false; }
		}
		return true;
	}

	// Time Limit Exceeded
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		vector<string> v1 = {strs[0]};
		res.push_back(v1);

		for (int j = 1; j < strs.size(); ++j) {
			auto str = strs[j];
			int idx = -1;
			for (int i = 0; i < res.size(); ++i) {
				auto group = res[i];
				if (is_anagram(group[0], str)) { idx = i; break; }
			}
			if (idx == -1) {
				res.push_back({str});
			} else {
				res[idx].push_back(str);
			}
		}

		return res;
    }

	vector<vector<string>> groupAnagrams_2(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> um;

		for (auto str : strs) {
			vector<int> v(26, 0);
			// sort(str.begin(), str.end());
			string tmp;
			for (char ch : str) { ++v[ch-'a']; }
			for (int num : v) { tmp += to_string(num); }
			um[tmp].push_back(str);
		}
		for (auto item : um) {
			res.push_back(item.second);
		}
		return res;
	}
};


void unit_test() {
	Solution s;

	vector<string> arr = {"eat", "tea", "tan", "ate", "nat", "bat"};
	auto res = s.groupAnagrams(arr);
	cout << res.size() << endl;

	for (auto group : res) {
		for (auto str : group) {
			cout << str << ", ";
		}
		cout << endl;
	}
}

int main() {
	unit_test();
	return 0;
}
