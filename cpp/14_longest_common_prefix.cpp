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
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int left = 0, right = 0;
        string res = "";
        int minLen = INT_MAX;

        for (auto str : strs) {
            if (str.size() < minLen) {
                minLen = str.size();
            }
            // minLen = std::min(str.size(), minLen);
        }
        int nsize = strs.size();
        bool prefixFlag = false;
        while (right < minLen) {
            bool flag = true;
            char ch = strs[0][right];
            for (int i = 1; i < nsize; ++i) {
                if (ch != strs[i][right]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                string substr = strs[0].substr(left, right-left+1);
                if (substr.size() > res.size()) {
                    res = substr;
                }
                ++right;
            } else {
                prefixFlag = true;
            }
            if (prefixFlag) { break; }
        }

        return res;
    }
};
