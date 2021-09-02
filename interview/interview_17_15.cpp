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
    string longestWord(vector<string>& words) {
		int nsize = words.size();
		if (nsize == 0) { return ""; }

		unordered_set<string> us(words.begin(), words.end());
		sort(words.begin(), words.end(), compare);

		for (int i = nsize-1; i >= 0; --i) {
			string word = words[i];
			us.erase(word);
			if (check(us, word)) { return word; }
		}

		return "";
    }

	bool check(unordered_set<string> us, string s) {
		int nsize = s.size();
		if (nsize == 0) { return true; }
		for (int i = 1; i <= nsize; ++i) {
			string sub = s.substr(0, i);
			if (us.find(sub) != us.end()) {
				string left = s.substr(i);
				if (check(us, left)) { return true; }
			}
		}
		return false;
	}
private:
	static bool compare(string s1, string s2) {
		if (s1.size() == s2.size()) {
			return s1 < s2;
		}
		return s1.size() < s2.size();
	}

};

