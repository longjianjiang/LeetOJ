// 让我们求下一个排列数，原地改变nums
// 逆序查找第一个非逆序的idx，如果当前排列已经全部逆序，那么需要进行reverse；
// 继续逆序查找第一个大于idx位置的数，进行swap；
// 最后从idx+1开始到nsize-1末尾这区间进行reverse；
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2) { return; }
		
		// find first ascending order idx
  		int nsize = (int)nums.size();
		int idx = -1;
		for (int i = nsize-1; i >= 1; --i) {
			if (nums[i-1] < nums[i]) {
				idx = i-1;
				break;
			}
		}

		// original nums is descending order, just reverse
		if (idx == -1) {
			for (int i = 0; i < nsize / 2; ++i) {
				swap(nums[i], nums[nsize-1-i]);
			}
			return;
		}

		// nornal condition
		for (int i = nsize-1; i > idx; --i) {
			if (nums[i] > nums[idx]) {
				swap(nums[i], nums[idx]);
                break;
			}
		}
		int particalSize = nsize-idx-1;
		int baseIdx = idx+1;
		for (int i = 0; i < particalSize / 2; ++i) {
			swap(nums[i+baseIdx], nums[particalSize-1-i+baseIdx]);
		}
    }
};
