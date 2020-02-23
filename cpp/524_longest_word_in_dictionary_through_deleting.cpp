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

// 给定字符串和字符串数组，要求返回数组中最长的并且字典序最小的字符串，可以通过s删除若干字符得到；
// 遍历数组，依次寻找出最长的并且字典序最小的即可；
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for (auto str : d) {
            int idx = 0;
            for (auto ch : s) {
                if (idx < str.size() && ch == str[idx]) { ++idx; }
            }
            if (idx == str.size() && str.size() >= res.size()) {
                if (str.size() > res.size() || str < res) { res = str; }
            }
        }
        return res;
    }
};
