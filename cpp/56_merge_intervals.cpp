// 给定有序区间，合并重叠的，按从小到达的顺序返回
// 首先将区间排序，然后遍历依次合并区间即可
class Solution {
public:
	// [0, 1] [3, 7] [2, 5] [6, 9] [10, 15]
	// [0, 1] [2, 7] [6, 9] [10, 15]
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.empty()) { return intervals; }
		sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
			return a[0] < b[0];
		});
		vector<vector<int>> res;
		res.push_back(intervals[0]);

		for (int i = 1; i < intervals.size(); ++i) {
			vector<int> tmp = res[res.size()-1];
			vector<int> cur = intervals[i];
			if (cur[0] <= tmp[0] || cur[0] <= tmp[1]) {
				res.pop_back();
				int start = cur[0] < tmp[0] ? cur[0] : tmp[0];
				int end = cur[1] > tmp[1] ? cur[1] : tmp[1];
				vector<int> merge = {start, end};
				res.push_back(merge);
			}else {
				res.push_back(cur);
			}
		}

		return res;
    }

};


