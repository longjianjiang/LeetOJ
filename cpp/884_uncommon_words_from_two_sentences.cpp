// 给定两个字符串，返回两个字符串中所有只出现一次的单词
// 使用unordered_map 进行判断即可
class Solution {
public:
	vector<string> split(string str, char sep) {
		vector<string> res;
		int idx = 0, pos = 0;
		while (idx < str.size()) {
			if (str[idx] == sep) {
				string sub = str.substr(pos, idx-pos);
				pos = idx+1;
				res.push_back(sub);
			}
			if (idx == str.size()-1) {
				res.push_back(str.substr(pos, idx-pos+1));
			}
			idx += 1;
		}
		return res;
	}

	vector<string> uncommonFromSentences(string A, string B) {
	    string str = A + " " + B;
		vector<string> items = split(str, ' ');

		unordered_map<string, int> dict;

		for (int i = 0; i < items.size(); ++i) {
			string sub = items[i];
			if (dict.find(sub) == dict.end()) {
				dict[sub] = 1;
			} else {
				dict[sub]++;
			}
		}

		vector<string> res;
		for (auto i = dict.begin(); i != dict.end(); ++i) {
			if (i->second == 1) { res.push_back(i->first); }
		}
		return res;
	}
};
