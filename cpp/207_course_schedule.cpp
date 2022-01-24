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

// directed graph find cycle.
// [ref](https://leetcode-cn.com/problems/course-schedule/solution/bao-mu-shi-ti-jie-shou-ba-shou-da-tong-tuo-bu-pai-/)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0) { return true; }
		unordered_map<int, unordered_set<int>> graph;
		unordered_map<int, int> degrees;

		for (auto p : prerequisites) {
			for (auto c : p) {
				if (degrees.find(c) == degrees.end()) { degrees[c] = 0; }
			}
			degrees[p[0]] += 1;
			graph[p[1]].insert(p[0]);
		}

		queue<int> q;
		for (auto d : degrees) {
			if (d.second == 0) { q.push(d.first); }
		}
		while (!q.empty()) {
			int id = q.front();
			q.pop();
			auto children = graph[id];
			for (auto c : children) {
				degrees[c] -= 1;
				if (degrees[c] == 0) { q.push(c); }
			}
		}
		for (auto d : degrees) {
			if (d.second != 0) { return false; }
		}
        return true;
    }
};
