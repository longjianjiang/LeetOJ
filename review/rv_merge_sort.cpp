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
void merge_sort(vector<int>& arr) {
	int nsize = arr.size();
	if (nsize <= 1) { return; }

	int mid = arr.size() / 2;
	vector<int> left = vector<int>(arr.begin(), arr.begin() + mid);
	vector<int> right = vector<int>(arr.begin() + mid, arr.end());

	merge_sort(left);
	merge_sort(right);
	
	int p = 0, q = 0;
	int pos = 0;
	while (p < left.size() && q < right.size()) {
		if (left[p] < right[q]) {
			arr[pos++] = left[p++];
		} else {
			arr[pos++] = right[q++];
		}
	}

	while (p < left.size()) { arr[pos++] = left[p++]; }
	while (q < right.size()) { arr[pos++] = right[q++]; } 
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

int main() {
	vector<int> arr1 = {2, 3, 1, 5, 4};
	merge_sort(arr1);
	show_arr_one_dimensional(arr1);

	vector<int> arr2 = {3, 3, 4, 3, 3};
	merge_sort(arr2);
	show_arr_one_dimensional(arr2);

	return 0;
}
