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
Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]

Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]
*/

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string word = "";
        string last = "";
        vector<string> res;
        vector<string> v = {first, second};

        for (auto ch : text) {
            if (ch == ' ') {
                if (v.empty()) {
                    res.push_back(word);
                    v = {first, second};
                }
                if (last == v[0] && word == v[1]) {
                    v.clear();
                    last = "";
                }
                last = word;
                word = "";
            } else {
                word += ch;
            }
        }

        if (v.empty() && !word.empty()) { res.push_back(word); }

        return res;
    }
};

