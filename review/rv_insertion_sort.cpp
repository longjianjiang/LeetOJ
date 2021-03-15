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

// 2 3 1 5 4
// 3 2 1 5 4
void insertion_sort(vector<int>& list) {
	int nsize = list.size();
	if (nsize <= 1) { return; }

	for (int i = 1; i < nsize; ++i) {
		int num = list[i];
		int pos = i-1;
		
		while (pos >= 0 && list[pos] > num) {
			list[pos+1] = list[pos];
			--pos;
		}
		list[pos+1] = num;
	}
}

void show_arr_one_dimensional(vector<int> arr) {
	cout << "[";
	for (int i = 0; i < arr.size(); ++i) {
		int num = arr[i];
		if (i == arr.size()-1) {
			cout << num;
		} else {
			cout << num << " ";
		}
	}
	cout << "]\n";
}

void show_arr_two_dimensional(vector<vector<int>> arr) {
	for (auto v: arr) {
		show_arr_one_dimensional(v);
	}
}

int main() {
	vector<int> arr1 = {2, 3, 1, 5, 4};
	insertion_sort(arr1);
	show_arr_one_dimensional(arr1);

	vector<int> arr2 = {3, 3, 4, 3, 3};
	insertion_sort(arr2);
	show_arr_one_dimensional(arr2);

	return 0;
}

