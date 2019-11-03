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

// vector<int> arr = {2, 1, 3, 7, 5};
// 1 2 3 7 5
int partition(vector<int>& arr, int low, int high) {
	int pivot = arr[low];
	while (low <= high) {
		while (arr[low] < pivot) { ++low; }
		while (arr[high] > pivot) { --high; }
		if (low <= high) {
			swap(arr[low], arr[high]);
			++low;
			--high;
		}
	}
	return low;
}

void quick_sort(vector<int>& arr, int low, int high) {
	int p = partition(arr, low, high);
	if (p-1 > low) { quick_sort(arr, low, p-1); }
	if (p < high) { quick_sort(arr, p, high); }
}

int partition_lomuto(vector<int>& arr, int low, int high) {
	int pivot = arr[high];
	int i = left;
	for (int j = low; j < high; ++j) {
		if (arr[j] < pivot) {
			if (i != j) { swap(arr[i], arr[j]); }
			++i;
		}
	}
	if (i == high) {
		return i-1;
	} else {
		swap(arr[i], arr[high]);
		return i;
	}
}

void qsort_lomuto(vector<int>& arr, int low, int high) {
	if (left >= high) { return; }
	int p = partition_lomuto(arr, low, high);
	qsort_lomuto(arr, left, p);
	qsort_lomuto(arr, p+1, high);
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

	cout << "======================\n";

	vector<int> arr = {2, 1, 3, 7, 5};
	quick_sort(arr, 0, 4);
	show(arr);

	return 0;
}
