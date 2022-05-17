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
    string simplifyPath(string path) {
		int nsize = path.size();
		if (nsize == 0) { return ""; }
		if (nsize == 1 && path[0] == '/') { return path; }
		if (path[0] != '/') { return ""; }

		vector<string> arr;
		int l = 0, r = 1;
		
		auto addSubpath = [&](string sub) {
			if (sub == ".") {

			} else if (sub == "..") {
				if (!arr.empty()) { arr.pop_back(); }
			} else {
				arr.push_back(sub);
			}
		};
		// "/home//foo"
		while (r < nsize) {
			if (path[r] == '/') {
				if (r - l > 1) {
					string sub = path.substr(l+1, r-l-1);
					addSubpath(sub);
					l = r;
				} else {
					++l;
				}
			} 
			++r;
		}
		if (l < nsize-1) {
			string sub = path.substr(l+1, nsize-l-1);
			addSubpath(sub);
		}

		string res = "/";
		for (int i = 0; i < arr.size(); ++i) {
			res += arr[i];
			if (i < arr.size()-1) { res += "/"; }
		}
		return res;
    }
};

void unit_test() {
	Solution s;

	cout << s.simplifyPath("/home/") << endl;
	cout << s.simplifyPath("/../") << endl;
	cout << s.simplifyPath("/home//foo") << endl;
	cout << s.simplifyPath("/a/./b/../../c/") << endl;
}

int main() {
	unit_test();
	return 0;
}
