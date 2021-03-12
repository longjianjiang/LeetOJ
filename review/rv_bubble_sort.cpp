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

// 冒泡排序
// 每次将最大的排到最后，直到数组有序；
// 3 5 1 4 2
//
void bubble_sort(vector<int>& list) {
	int nsize = list.size();
	if (nsize <= 1) { return; }

	bool swapped;
	for (int i = 0; i < nsize-1; ++i) {
		swapped = false;
		for (int j = 0; j < nsize-1-i; ++j) {
			if (list[j] > list[j+1]) {
				swap(list[j], list[j+1]);
				swapped = true;
			}
		}
		if (!swapped) { break; }
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
	bubble_sort(list_1);
	show_arr_one_dimensional(list_1);

	vector<int> list_2 = {3, 3, 4, 3, 3};
	bubble_sort(list_2);
	show_arr_one_dimensional(list_2);

	return 0;
}
