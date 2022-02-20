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

// [0, 1, 2, 3, 4] 3
int lastRemaining(int n, int m) {
	if (n < 1 || m < 1) { return -1; }

	vector<int> list(n, 0);
	for (int i = 0; i < n; ++i) {
		list[i] = i;
	}
	int idx = 0;
	while (list.size() > 1) {
		idx += m-1;
		int updatedIdx = idx % list.size();
		list.erase(list.begin() + updatedIdx);
		idx = updatedIdx;
	}

	return list[0];
}
