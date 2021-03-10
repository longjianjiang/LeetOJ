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

int partition_1(vector<int>& list, int left, int right) {
	int pivot = list[left];
	int pos = left;
	for (int i = left+1; i <= right; ++i) {
		if (list[i] <= pivot) {
			++pos;
			if (i != pos) { swap(list[i], list[pos]); }
		}
	}
	swap(list[pos], list[left]);

	return pos;
}

int partition_2(vector<int>& list, int left, int right) {
	int pivot = list[left];
	int i = left, j = right;
	while (i < j) {
		while (i < j && list[j] >= pivot) { --j; }
		if (i < j) { list[i] = list[j]; }
		while (i < j && list[i] <= pivot) { ++i; }
		if (i < j) { list[j] = list[i]; }
	}
	list[i] = pivot;

	return i;
}

void quick_sort_1(vector<int>& list, int left, int right) {
	if (left >= right) { return; }

	int pos = partition_1(list, left, right);
	quick_sort_1(list, left, pos-1);
	quick_sort_1(list, pos+1, right);
}

void quick_sort_2(vector<int>& list, int left, int right) {
	if (left >= right) { return; }

	int pos = partition_2(list, left, right);
	quick_sort_2(list, left, pos-1);
	quick_sort_2(list, pos+1, right);
}

// 3 6 1 5 4
// 1 6 1 5 4
// 1 6 6 5 4
int main() {
	vector<int> list = {3, 3, 4, 3, 3};
	quick_sort_1(list, 0, 4);
	show_arr_one_dimensional(list);

	vector<int> list_2 = {3, 3, 4, 3, 3};
	quick_sort_2(list_2, 0, 4);
	show_arr_one_dimensional(list_2);

	return 0;
}
