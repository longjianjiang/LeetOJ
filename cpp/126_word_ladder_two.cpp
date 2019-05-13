// 和127类似，只是这题让我们返回最短路径的数组
// 思路是挨个和wordList里去比较，不断的去替换list，当遇到单词为endWord，此时结束，path肯定是最短的，
// 返回之前遍历list，去除最后单词不是endWord的path

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> us = {wordList.begin(), wordList.end()};
		if (us.count(endWord) == 0) { return {}; }
		if (us.count(beginWord) && beginWord.size()==1) { return {{beginWord, endWord}}; } // a, c, [a, b, c] case
		if (us.count(beginWord)) { us.erase(beginWord); }

		auto minSize = wordList.size()+2;
		vector<vector<string>> list;
		list.push_back({ beginWord });
		while (!us.empty()) {
			vector<vector<string>> update;
			vector<string> erases;
			for (int j = 0; j < list.size(); ++j) {
				vector<string> path = list[j];
				string str = path[path.size()-1];
				vector<string> matchs;
				for (int i = 0; i < str.size(); ++i) {
					for (char c = 'a'; c <= 'z'; ++c) {
						if (str[i] != c) {
							string tmp = str;
							tmp[i] = c;
							if (us.count(tmp)) {
								matchs.push_back(tmp);
								erases.push_back(tmp);
							}
						}
					}
				}

				for (int i = 0; i < matchs.size(); ++i) {
					string str = matchs[i];
					if (str == endWord) { minSize = path.size()+1; }
					vector<string> tmp = path;
					tmp.push_back(matchs[i]);
					update.push_back(tmp);
				}
			}

			// red, tax, ["ted","tex","red","tax","tad","den","rex","pee"] case
			// str in wordList should erase after one time select
			for (auto str: erases) {
				us.erase(str);
			}

			if (update.empty()) { return {}; } // hot dot [hot, dog] case
			list = update;
			if (minSize <= wordList.size()+1) {
				break;
			}
		}

		vector<vector<string>> res;
		for (int i = 0; i < list.size(); ++i) {
			vector<string> path = list[i];
			if (path[minSize-1] == endWord) { res.push_back(path); }
		}
		return res;

    }
};
