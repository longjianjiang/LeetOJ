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

// 给定数独，验证是否合法，遍历即可，依次遍历3*3的小方格，同时记录横纵方向是否重复。
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> list_v(9, unordered_set<char>());
        
        for (int i = 0; i < 3; ++i) {
            vector<unordered_set<char>> list_h(3, unordered_set<char>());
            for (int j = 0; j < 3; ++j) {
                unordered_set<char> us_1;
                for (int m = i * 3; m < 3 + 3*i; ++m) {
                    for (int n = j * 3; n < 3 + 3*j; ++n) {
                        char c = board[m][n];
                        if (c == '.') { continue; }
                        
                        if (us_1.find(c) != us_1.end()) {
                            return false;
                        }
                        
                        auto us_h = list_h[m-3*i];
                        auto us_v = list_v[n];
                        
                        if (us_h.find(c) != us_h.end()) {
                            return false;
                        }                    
                        if (us_v.find(c) != us_v.end()) {
                            return false;
                        }

                        us_1.insert(c);
                        list_h[m-3*i].insert(c);
                        list_v[n].insert(c);
                    }
                }
            }
        }
        return true;
    }
};


