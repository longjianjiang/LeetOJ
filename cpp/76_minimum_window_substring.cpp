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
    string minWindow(string s, string t) {
		if (s == t) { return s; }
		if (t.size() > s.size()) { return ""; }

		int pos1 = 0, pos2 = 0;
		unordered_set<char> us, needed;
		for(int i = 0; i < t.size(); ++i) {
			us.insert(t[i]);
			needed.insert(t[i]);
		}

		string retStr = "";
		int len = s.size() + t.size();
		bool flag = false;
		while(pos1 < s.size()) {
			if (!flag && us.empty()) {
				if (needed.find(s[pos2]) != needed.end()) {
					for(int i = 0; i < t.size(); ++i) {
						if (t[i] != s[pos2]) {
							us.insert(t[i]);
						}
					}
					pos1 = pos2+1;
					continue;
				}	
				pos2++;
				continue;
			}
			char ch = s[pos1];
			if (!flag && us.find(ch) == us.end()) {
				pos2 = ++pos1;
				continue;
			}
			flag = true;
			if (us.find(ch) != us.end()) {
				us.erase(ch);
				if (us.empty()) {
					flag = false;
					string sub = s.substr(pos2, pos1-pos2+1);
					cout << sub << endl;
					if (sub.size() < len) { retStr = sub; len = sub.size(); }
					pos2++;;
					continue;
				} 
			}
			pos1++;
		}

		return retStr;
    }
};

void unit_test() {
	Solution s;

	assert(s.minWindow("ADOBECODEBANC", "ABC") == "BANC");
	assert(s.minWindow("a", "b") == "");
	assert(s.minWindow("a", "aa") == "");
	assert(s.minWindow("bdab", "ab") == "ab");
	assert(s.minWindow("ab", "a") == "a");
}

int main(){
	unit_test();

	 return 0;
}
