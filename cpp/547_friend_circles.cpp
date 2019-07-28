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

// 给定n*n二维数组，m[i][j]表示i和j是朋友，同时具有传递性，问朋友圈的个数。
// 一种极端的情况，这n个人互相都不是朋友，这个时候就有n个朋友圈。也就是此时有n个集合，当某两个人是朋友的时候，需要合并集合。而且合并需要进行查询是不是已经在一个集合中了。
// 上述所说的其实就是所谓的并查集(union find)，两个核心操作union，find。
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
		int nsize = M.size();
		int count = nsize;
		if (nsize == 0) { return 0; }

		vector<int> sec(nsize, 0);
		for (int i = 0; i < nsize; ++i) {
			sec[i] = i;
		}

		auto find = [&](int i) {
			while (i != sec[i]) {
				sec[i] = sec[sec[i]];
				i = sec[i];
			}
			return i;
		};

		auto unionf = [&](int i, int j) {
			int left = find(i);
			int right = find(j);
			if (left != right) {
				sec[right] = left;
				count--;
			}
        };

		for (int i = 0; i < nsize; ++i) {
			for (int j = i+1; j < nsize; ++j) {
				if (M[i][j] == 1) {
					unionf(i, j);
				}
			}
		}

		return count;
    }
};


