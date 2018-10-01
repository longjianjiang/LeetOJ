#include<iostream>
#include<vector>

using namespace std;

/*
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/

// 给定有序数组和target，找出两个元素和为target，返回下标数组，首下标小于尾下标
// 依然可以用第一次的那种map的方法，但是效率不够高，没有利用数组有序
// 此时可以使用头尾两个节点，依次相加判断与target的大小

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int i = 1, j = numbers.size();
        while (i <= j) {
            if (numbers[i-1] + numbers[j-1] == target) {
                result.push_back(i);
                result.push_back(j);
                break;
            } else if (numbers[i-1] + numbers[j-1] > target) {
                j -= 1;
            } else {
                i += 1;
            }
        }

        return result;
    }
};
