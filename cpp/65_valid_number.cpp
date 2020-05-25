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

// 给定字符串，判断是否为合法的数字；
// 首先去除首尾空格，然后遍历判断即可；
class Solution {
public:
    bool isNumber(string s) {
		int left = 0, right = s.length()-1;
		bool symbol = false;
		bool point = false;
		bool eChar = false;
		bool hasNumber = false;
        bool eRightNumber = false;

		while (left <= right) {
			if (s[left] == ' ') { left++; continue; }
			break;
		}
		while (right >= left) {
			if (s[right] == ' ') { right--; continue; }
			break;
		}
		while (left <= right) {
			char ch = s[left];

			if (ch == '+' || ch == '-') {
                if (eRightNumber) { return false; } // case "11e11+"
                if (!eChar && (hasNumber || point)) { return false; } // case "1+", "1.+"
				if (symbol && !eChar) { return false; }
				symbol = true;
                ++left; continue; 
			}
			if (ch == 'e') {
                if (eChar) { return false; }
				if (!hasNumber) { return false; }
				eChar = true;
                ++left; continue;
			}
			if (ch == '.') {
                if (eChar || eRightNumber) { return false; } // case "1e.", "1e3."
				if (point) { return false; }
                point = true;
                ++left; continue;
			}
			if (!(ch >= 48 && ch <= 57)) { return false; }
			if (!hasNumber) { hasNumber = true; }
            if (eChar) { eRightNumber = true; }
			++left;
		}	
        if (eChar) {
            return hasNumber && eRightNumber;
        }
        return hasNumber;      
    }
};
