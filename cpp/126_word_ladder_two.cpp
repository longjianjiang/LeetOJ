class Solution {
public:

	void bfs(string bw, string ew, unordered_set<string>& us, vector<string>& chosen, vector<vector<string>>& res) {
		if (bw == ew) {
			chosen.push_back(ew);
			res.push_back(chosen);
			return;
		}

		chosen.push_back(bw);

		for(int i = 0; i < bw.size(); ++i) {
			for(char j = 'a'; j <= 'z'; ++j) {
				if (bw[i] != j) {
					string tmp = bw;
					tmp[i] = j;
					if (us.count(tmp)) {
						us.erase(tmp);
						bfs(tmp, ew, us, chosen, res);
						chosen.pop_back();
						us.insert(tmp);
					}
				}
			}
		}
	}
	
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string> us = {wordList.begin(), wordList.end()};
	   if (us.count(endWord) == 0) { return {}; }

	   vector<vector<string>> tmp;
	   vector<string> chosen;
	   bfs(beginWord, endWord, us, chosen, res);

	   return tmp;
    }
};
