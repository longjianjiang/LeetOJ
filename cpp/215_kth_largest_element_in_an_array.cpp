
// 给定一个无序数组，让我们找到数组中第k大的数字

// 使用堆，首先取数组中前k个建最小堆，然后从k位置开始遍历数组，当遇到有比堆顶大的数字时，将其入堆，最后返回堆顶元素即可

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> minHeap;
        for (int i = 0; i < k; ++i) {
        	minHeap.push_back(nums[i]);
        }
        make_heap(minHeap.begin(), minHeap.end(), compare);

        for (int i = k; i < nums.size(); ++i) {
        	if (nums[i] > minHeap[0]) {
        		pop_heap(minHeap.begin(), minHeap.end(), compare);
        		minHeap.pop_back();

        		minHeap.push_back(nums[i]);
        		push_heap(minHeap.begin(), minHeap.end(), compare);
        	}
        }

        return minHeap[0];
    }
private:
    static bool compare(int num1, int num2) {
        return num1 > num2;
    }
};