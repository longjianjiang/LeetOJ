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
    bool isNumber(string s) {
        if (s == " ") { return false; }
		int idx = 0;
		bool symbol = false;
		bool point = false;
		bool eChar = false;
		bool hasNumber = false;
        bool eRightNumber = false;
        bool space = false;

		while (idx < s.length()) {
			if (s[idx] == ' ') { idx++; continue; }
			break;
		}
		while (idx < s.length()) {
			char ch = s[idx];

			if (ch == '+' || ch == '-') { 
				if (symbol && !eChar) { return false; }
                if (space) { return false; }
				symbol = true;
                ++idx; continue; 
			}
			if (ch == 'e') {
				if (!hasNumber) { return false; }
                if (space) { return false; }
				eChar = true;
                ++idx; continue;
			}
			if (ch == '.') {
				if (point) { return false; }
                if (space) { return false; }
                point = true;
                ++idx; continue;
			}
            // ". 1"
            // "1 2"
            // "12 "
            // ". "
            // "1 ."
            if (space && (ch >= 48 && ch <= 57)) { return false; }
            if (ch == ' ') { space = true; }
			if (!(ch >= 48 && ch <= 57)) {
                if (!hasNumber) { return false; }
                if (!space) { return false; } 
            }

			if (!hasNumber) { hasNumber = true; }
            if (eChar) { eRightNumber = true; }
			++idx;
		}	
        if (eChar) {
            return hasNumber && eRightNumber;
        }
        return hasNumber;
    }
};
