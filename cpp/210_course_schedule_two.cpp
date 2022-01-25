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

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> res;

		unordered_map<int, unordered_set<int>> graph;
		unordered_map<int, int> degrees;

		for (auto p : prerequisites) {
			// for (auto d : p) {
			// 	if (degrees.find(d) == degrees.end()) { degrees[d] = 0; }
			// }
			degrees[p[0]] += 1;
			graph[p[1]].insert(p[0]);
		}

		queue<int> q;
		// 所有课程为0入度
		for (int i = 0; i < numCourses; ++i) {
			if (degrees[i] == 0) { q.push(i); }
		}

		while (!q.empty()) {
			auto id = q.front(); q.pop();
			res.push_back(id);

			auto children = graph[id];
			for (auto c : children) {
				degrees[c] -= 1;
				if (degrees[c] == 0) { q.push(c); }
			}
		}

		if (res.size() == numCourses) {
            return res;
        } else {
            return {};
        }
    }
};
