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
 * "abc" => "cba"
 * "abcd" => "dcba"
 */
void reverse_string(string &str) {
	int nsize = str.size();
	if (nsize <= 1) { return; }

	int i = 0, j = nsize - 1;
	while (i < j) {
		swap(str[i], str[j]);
		++i;
		--j;
	}
}

void unit_test() {
	string str1 = "abc";
	string str2 = "abcd";

	reverse_string(str1);
	reverse_string(str2);

	cout << str1 << endl;
	cout << str2 << endl;
	cout << "--------------------------------" << endl;
}

int main() {
	unit_test();
	return 0;
}
