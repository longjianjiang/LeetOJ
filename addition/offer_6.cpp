#include <iostream>
#include <vector>

using namespace std;

// 给定一个旋转数组，数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，求旋转数组中的最小值
// 三种思路
// 1. 一次遍历，找到最小的即可
// 2. 因为数组依然是部分有序，只需要找到 arr[i] > arr[i+1]，此时返回arr[i+1] 即可
// 3. 二分查找，依然利用数组部分有序

int minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.empty()) { return 0; }
    int left = 0, right = (int)rotateArray.size()-1;
    while (left < right) {
        if (rotateArray[left] < rotateArray[right]) { return rotateArray[left]; }
        int mid = left + (right-left) / 2;
    
        if (rotateArray[mid] > rotateArray[left]) {
            // 此时位于前半段有序数组中
            left = mid + 1;
        } else if (rotateArray[mid] < rotateArray[right]) {
            // 此时位于后半段有序数组中
            right = mid;
        } else {
            // 此时 left, mid, right 三个位置的元素相等，类似 [1, 0, 1, 1, 1]
            left++;
        }
    }

    return rotateArray[left];
}

void test(vector<int> arr) {
    cout << "RotateArrary: ";
    for (auto num : arr) {
        cout << num << " ";
    }
    cout << "\nMinNumber: " << minNumberInRotateArray(arr) << endl;
}

int main() {
    test({1, 2, 3, 4, 5}); // MinNumber: 1
    test({1, 0, 1, 1, 1}); // MinNumber: 0
    test({3, 4, 5, 1, 2}); // MinNumber: 1

    return 0;
}