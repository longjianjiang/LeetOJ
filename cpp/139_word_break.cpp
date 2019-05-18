class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
		if (wordDict.empty()) { return false; }
		unordered_set<string> us = {wordDict.begin(), wordDict.end()};
		int nsize = (int)s.size();
		vector<int> arr = {0};
		vector<int> dp(nsize+1, 0);
		for (int i = 0; i <= nsize; ++i) {
			for (auto p: arr) {
				string seg = s.substr(p, i-p);
				if (us.count(seg)) {
					dp[i] = 1;
					arr.push_back(i);
					break;
				}
			}
		}
		return dp[nsize] == 1;
     
    }
};
