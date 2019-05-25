//  将字符串转为int
// 1.去除开头的空格，当第一个字符不是数字和正负号时直接返回0
// 2.取数字，当遇到不是数字后停止
// 3.返回范围为32位整形范围
class Solution {
public:
    int myAtoi(string str) {
 		if (str.empty()) { return 0; }
		bool first = true;
		unordered_set<char> symbols = {'+', '-'}, numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
		double res = 0;
		int pos = 0, positive = 1;
		stack<int> s;
		
		for (int i = 0; i < str.size(); ++i) {
			if (first && str[i] == ' ') { continue; }
			if (first) {
				if (symbols.count(str[i])) {
					if (str[i] == '-') { positive = -1; }
				} else if (numbers.count(str[i])) {
					int number = str[i] - '0';
					if (s.empty() && number == 0) { first = false; continue; }
					s.push(number);
				} else {
					return 0;
				}
				first = false;
			} else {
				if (!numbers.count(str[i])) { break; }
				int number = str[i] - '0';
				if (s.empty() && number == 0) { continue; }
				s.push(number);
			}
		}
		
		while (!s.empty()) {
			if (res > INT_MAX) {
				return positive > 0 ? INT_MAX : INT_MIN;
			}
			res += s.top() * pow(10, pos++);
			s.pop();
		}
		if (res > INT_MAX) {
			return positive > 0 ? INT_MAX : INT_MIN;
		}
		res *= positive;
		return (int)res;
    }
};
