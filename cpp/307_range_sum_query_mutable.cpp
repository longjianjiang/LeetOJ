
// 给定数组，新建一个类，对数组进行range求和以及更新数组，这两个操作比例均等
// 为了保证查询和更新同样的时间复杂度，只能使用二叉索引树和线段树，可以保证时间复杂度均为O(logN)

class NumArray {
public:
    NumArray(vector<int> nums) {
        arr.resize(nums.size()+1);
        data.resize(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int diff = val - data[i];
        if (i+1 < arr.size()) {
            int idx = i+1;
            while (idx < arr.size()) {
                arr[idx] += diff;
                idx += idx & (-idx);
            }
            data[i] = val;
        }
    }
    
    int sumRange(int i, int j) {
        return rangeTo(j) - rangeTo(i-1);
    }
    
private:
    vector<int> arr, data;

    int rangeTo(int pos) {
        if (pos+1 < arr.size()) {
            int res = 0;
            int idx = pos + 1;
            while (idx) {
                res += arr[idx];
                idx -= idx & (-idx);
            }
            return res;
        }
        return 0;
    }
};