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

// 四位密码锁，给定一组数据导致密码锁坏了，要求给出最短的step到正确的密码，如果不存在则返回-1；
// bfs，基本模式是队列存一个初始化值，一个set过滤已遍历过的。对队列中的密码中每一位进行上下转动也就是值加1或减1。
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
		queue<string> q ( {"0000"} );
		unordered_set<string> visited;
		for (auto item : deadends) { visited.insert(item); }
		int step = 0;

		while (!q.empty()) {
			for (int i = q.size(); i > 0; --i) {
				auto item = q.front(); q.pop();
				if (visited.find(item) != visited.end()) { continue; }
				if (item == target) { return step; }

				for (int j = 0; j < 4; ++j) {
					for (int k = -1; k < 2; k += 2) {
						string updated = item;
						updated[j] = '0' + (updated[j] - '0' + k + 10) % 10;
						q.push(updated);
					}
				}
				visited.insert(item);
			}
			++step;
		}
		return -1;
    }
};
