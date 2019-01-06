// 本题给定一个数组，k大小的窗口，移动窗口，每次取窗口中的最大值，放到数组，最后将数组返回；
// 使用 STL 中的 deque，双端队列，头尾都可以插入删除，
// 所以我们新建一个 dp， 初始化 k 个元素，这里我们保证 dp 中只存储最大的，移动window时，
// 1. 删除元素判断需要删除的元素如果是dp的front，将其pop_front,
// 2. 添加元素则使用之前的添加策略，
// 一次window移动结束，将dp 的 front 添加的数组中，最后返回即可。

class Solution {
public:
	void addItemIntoDp(deque<int>& dp, int num) {
		while (!dp.empty() && num > dp.back()) {
			dp.pop_back();
		}
		dp.push_back(num);
	}

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        vector<int> res;
        deque<int> dp;
        for (int i = 0; i < k; ++i) {
        	addItemIntoDp(dp, nums[i]);
        }
        res.push_back(dp.front());
        for (int i = 0; i < nums.size()-k; ++i) {
        	if (nums[i] == dp.front()) { dp.pop_front(); }
        	addItemIntoDp(dp, nums[i+k]);
        	res.push_back(dp.front());
        }
        return res;
    }
};