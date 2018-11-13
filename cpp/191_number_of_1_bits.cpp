#include <iostream>
using namespace std;

// 给定一个32位无符号整数，给出其二进制形式中1的个数
// 依次将数字与1进行&，然后右移一位，直到数字为0

class Solution {
public:
    int hammingWeight(uint32_t n) {
      int result = n & 1;
      while (n = n >> 1) {
        result += n & 1;
      }
      return result;
    }
};

