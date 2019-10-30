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

// 给定数组，表示的是一圈公交站点，[i]表示站点i到站点(i+1)/n之间的距离，给定任意两个节点，给出最短距离。
// 直接逆时针，顺时针分别算出距离，返回较小的即可。
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
		int nsize = (int)distance.size();

		if (start > destination) { swap(start, destination); }
		int idx = start;
		int lenOne = 0, lenTwo = 0;

		while (idx < destination) {
			lenOne += distance[idx++];
		}
		idx = destination;
		while (idx > 0) {
			lenTwo += distance[idx];
			idx = (idx+1) % nsize;
		}
		while (idx < start) {
			lenTwo += distance[idx];
			idx = (idx+1) % nsize;
		}
		return min(lenOne, lenTwo);
    }
};
