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

vector<int> get_next(const char* p) {
	int nsize = (int)strlen(p);
	vector<int> next(nsize, 0); next[0] = -1;

	int k = -1, j = 0;
	while (j < nsize-1) {
		if (k==-1 || p[j]==p[k]) {
			if (p[k+1]==p[j+1]) {
				next[++j] = next[++k];
			} else {
				next[++j] = ++k;
			}
		} else {
			k = next[k];
		}
	}
	return next;
}

vector<int> find(const char* s, const char* p) {
	vector<int> res;
	if (strlen(p) == 0) { return res; }
	if (strlen(p) == 1) {
		for (int i = 0; i < strlen(s); ++i) {
			if (s[i] == p[0]) { res.push_back(i); }
		}
		return res;
	}

	int i = 0, j = 0;
	int l1 = strlen(s), l2 = strlen(p);
	vector<int> next = get_next(p);
	while (i < l1) {
		if (j == -1 || s[i]==p[j]) {
			i++; j++;
			if (j == l2) {
				res.push_back(i-l2);
				j = 0;
			}
		} else {
			j = next[j];
		}
	}

	return res;
}

char* replace(const char* str, const char* from, const char* to) {
	if (strlen(str) == 0) { return NULL; }

	vector<int> idxs = find(str, from);
	for (auto idx : idxs) { cout << idx << endl; }
	int diff = strlen(to) - strlen(from);
	int nsize = strlen(str)+(diff * idxs.size());

	char *res = (char *)malloc(nsize);
	int i = 0, k = 0;
	while (!idxs.empty() && i < strlen(str)) {
		if (i == idxs[0]) {
			for (int j = 0; j < strlen(to); ++j) {
				res[k+j] = to[j];
			}
			i += strlen(from);
			k += strlen(to);
			idxs.erase(idxs.begin());
		} else {
			res[k++] = str[i++];
		}
	}
	return res;
}

void unit_test() {
	char *c_str = "abbcdeebfbb";
	char *updated = replace(c_str, "bb", "");

	cout << c_str << endl;
	cout << updated << endl;
}

int main() {
	unit_test();

	return 0;
}
