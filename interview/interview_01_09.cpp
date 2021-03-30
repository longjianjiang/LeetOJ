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

/*
 字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。
  输入：s1 = "waterbottle", s2 = "erbottlewat"
 输出：True
 */

// 拼接s1+s1，如果是旋转，那么s2一定是子串。
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) { return false; }
        if (s1.empty() && s2.empty()) { return true; }

        string str = s1+s1;
        return str.find(s2) != string::npos;
    }
};
