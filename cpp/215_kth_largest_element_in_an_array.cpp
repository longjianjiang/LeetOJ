
// 给定一个无序数组，让我们找到数组中第k大的数字

// 使用堆，首先取数组中前k个建最小堆，然后从k位置开始遍历数组，当遇到有比堆顶大的数字时，将其入堆，最后返回堆顶元素即可。

// 另一种思路，类似快速排序的partition，将数组进行拆分，选择一个参照数，一次拆分将数组中小于参照数的放到左边，大于参照数的放到右边，
// 然后返回参照数的索引，如果 索引 等于 size-k，那么直接返回该索引的数字，否则递归两边，直到找到。

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

    int findKthLargestPartition(vector<int>& nums, int left, int right) {
    	int pivot = nums[left];
    	int i = left + 1, j = right;
    	while (i <= j) {
    		if (nums[i] > pivot && nums[j] < pivot) {
    			swap(nums[i++],nums[j--]);
    		}
    		if (nums[i] <= pivot) {
    			i++;
    		}
    		if (nums[j] >= pivot) {
    			j--;
    		}
    	}
    	swap(nums[left],nums[j]);
    	return j;
    }
    
    int findKthLargestVersion2(vector<int>& nums, int k) {
    	int left = 0, right = nums.size() - 1;
    	int target = (int)(nums.size()-k);
    	while (1) {
    		int p = findKthLargestPartition(nums, left, right);
    		if (target == p) {
    			return nums[target];
    		} else if (target > p) {
    			left = p+1;
    		} else {
    			right = p-1;
    		}
    	}
    }

private:
    static bool compare(int num1, int num2) {
        return num1 > num2;
    }
};