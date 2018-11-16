#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 给定一个字符串由 ACGT 组成，要求我们找到所有出现不止一次的长度为10的子串。
// 一个直觉的思路，遍历字符串，每个长度为10的子串存到字典中，根据字典中的判断，如果存在则是符合要求的。
// 不过上述方式会占比较大的空间，所以为了节省空间我们可以只用这四个字母的后三位来代表四个字母，这样10个字母只需要30位，一个int型就够了

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.length <= 10) return res;

        unordered_map<int, int> dict;
        int mask = 0x7ffffff;
        int cur = 0, i = 0;
        while (i < 9) {
            cur = (cur << 3) | (s[i++] & 7);
        }

        while (i < s.size()) {
            cur = ((cur & mask) << 3) | (s[i++] & 7);
            if (dict.find(cur) != dict.end()) {
                if (dict[cur] == 1) res.push_back(s.substr(i-10, 10));
                dict[cur]++;
            } else {
                dict[cur] = 1;
            }
        }
        return res;
    }
};