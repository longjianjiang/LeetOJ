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
 *
 * [2,3,1,4,5]
 */
void bubble_sort(vector<int>& arr) {
	int nsize = arr.size();
	if (nsize <= 1) { return; }
	for (int i = 0; i < nsize; ++i) {
		int num1 = arr[i];
		for (int j = i + 1; j < nsize; ++j) {
			int num2 = arr[j];
			if (num2 < num1) {
				arr[i] = num2;
				arr[j] = num1;
			}
		}
	}
}

void unit_test() {
	vector<int> arr = {2,3,1,4,5};
	bubble_sort(arr);
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << ",";
	}
	cout << endl;
}

int main() {
	unit_test();
	return 0;
}
