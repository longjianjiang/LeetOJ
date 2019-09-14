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

void show(vector<int>& list) {
	for (auto num : list) {
		cout << num << " ";
	}
	cout << endl;
}

int main() {
	vector<int> v1 = {1, 3, 5, 7};
	vector<int> v2 = v1;

	v2.pop_back();

	show(v1);
	show(v2);

	cout << "======================\n";

	string s1 = "nancy";
	string s2 = s1 + " botwin";

	cout << s1 << ", " << s2 << endl;
	return 0;
}
