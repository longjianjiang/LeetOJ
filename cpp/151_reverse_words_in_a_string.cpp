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

// 给定一个字符串，要求将其倒置，返回倒置后的字符串；要求去除首尾空格，单词之间多余的空格；
class Solution {
public:
    string reverseWords(string s) {
       int idx = 0;
	   int nsize = (int)s.size();
	   while (idx < nsize && s[idx] == ' ') { ++idx; }

	   int start = idx;
	   vector<string> v;
	   while (idx < nsize) {
		   if (s[idx] == ' ') {
			   if (s[start] != ' ') {
				   string sub = s.substr(start, idx-start);
				   v.push_back(sub);
			   }
			   start = idx+1;
		   }
		   ++idx;
	   }
	   if (start < nsize && s[start] != ' ') {
		   v.push_back(s.substr(start, idx-start));
	   }
	   string res;
	   
	   for (int i = v.size()-1; i >= 0; --i) {
		   res += v[i];
		   if (i != 0) { res += " "; }
	   }
	   return res;
    }
};

void unit_test() {
	Solution s;
	string str = "  hello world!  ";
	cout << s.reverseWords(str); 
	cout << "<end>\n";
}

int main() {
	unit_test();
	return 0;
}
