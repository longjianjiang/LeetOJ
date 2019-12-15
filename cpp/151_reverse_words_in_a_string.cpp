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

	string reverseWordsInPlace(string s) {
		auto reverseFunc = [](string& s, int l, int r) {
			while (l < r) {
				swap(s[l], s[r]);
				++l; --r;
			}
		};

	   reverseFunc(s, 0, s.size()-1);
       int idx = 0, start = 0;
	   int nsize = (int)s.size();
	   while (idx < nsize && s[idx] == ' ') { s.erase(s.begin()+idx); }

	   while (s.begin()+idx < s.end()) {
		   if (s[idx] == ' ') {
               reverseFunc(s, start, idx-1);
			   ++idx; // add space
			   while (s[idx] == ' ') { s.erase(s.begin()+idx); } // remove extra space
			   start = idx;
		   }
		   ++idx;
	   }
	   if (s[start] != ' ') { reverseFunc(s, start, idx-1); }
	   if (*(s.end()-1) == ' ') { s.erase(s.end()-1); }
	   return s;
	}
};

void show(string str) {
	Solution s;
	cout << "<start>";
	cout << s.reverseWordsInPlace(str); 
	cout << "<end>\n";
}
void unit_test() { 
	string str1 = "  hello   world!  ";
	string str2 = "nancy jiang";
	show(str1);
	show(str2);
}

int main() {
	unit_test();
	return 0;
}
