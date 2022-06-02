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

// " fly me   to   the moon  "
// "Hello  World"
class Solution {
public:
    int lengthOfLastWord(string s) {
		int nsize = s.size();
		if (nsize == 0) { return 0; }

		int l = 0, r = 0;
		int res = 0;
		while (r < nsize) {
			if (s[r] == ' ') {
				res = r - l;
				while (r + 1 < nsize && s[r+1] == ' ') {
					++r;
				}
				l = r + 1;
			} 
			++r;
		}
		if (l < nsize) { res = nsize - l; }
		return res;
    }
};

void unit_test() {
	Solution s;

	cout << s.lengthOfLastWord("   fly me   to   the moon  ") << endl;
	cout << s.lengthOfLastWord("hello world") << endl;
	cout << s.lengthOfLastWord("luffy is still joyboy") << endl;
}

int main() {
	unit_test();
	return 0;
}
