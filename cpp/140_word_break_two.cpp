class Solution {
public:
	void bfs(string s, int idx, unordered_set<string> dict, vector<int>& chosen, vector<vector<int>>& res) {
		if (idx >= s.size()) {
			res.push_back(chosen);
			return;
		}

		int nsize = (int)s.size();
		for (int i = idx+1; i <= nsize; ++i) {
			string seg = s.substr(idx, i-idx);
			if (dict.count(seg)) {
				chosen.push_back(i);
				bfs(s, i, dict, chosen, res);
				chosen.pop_back();
			}
		}
	}

	vector<string> wordBreak(string s, vector<string>& wordDict) {
		if (wordDict.empty()) { return {}; }
		unordered_set<string> us = {wordDict.begin(), wordDict.end()};
		vector<vector<int>> posList;
		vector<int> chosen;

		bfs(s, 0, us, chosen, posList);

		vector<string> res;
		for (auto list: posList) {
			string str;
			int pos = 0;
			for (int i = 0; i < list.size(); ++i) {
				int idx = list[i];
				string seg = s.substr(pos, idx-pos);
				str += seg;
				if (i < list.size()-1) { str += " "; }
				pos = idx;
			}
			res.push_back(str);
		}
		return res;
	}
};
