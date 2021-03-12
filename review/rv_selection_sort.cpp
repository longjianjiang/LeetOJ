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

// 选择排序
// 一次遍历，将最小的提前；
void selection_sort(vector<int>& list) {
	int nsize = list.size();
	if (nsize <= 1) { return; }

	for (int i = 0; i < nsize; ++i) {
		int idx = i;
		for (int j = i+1; j < nsize; ++j) {
			if (list[j] < list[idx]) {
				idx = j;
			}
		}
		swap(list[i], list[idx]);
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
	vector<int> list_1 = {3, 5, 1, 4, 2};
	selection_sort(list_1);
	show_arr_one_dimensional(list_1);

	vector<int> list_2 = {3, 3, 4, 3, 3};
	selection_sort(list_2);
	show_arr_one_dimensional(list_2);
	return 0;
}
