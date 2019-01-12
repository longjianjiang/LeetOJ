#include <iostream>

using namespace std;

// 要求给定字符串，让我们将其中的空格，变为 "%20", 当然不是让我们使用内置的replace函数
// 首先计算出空格的个数，然后从后往前替换即可

// "A P P L E "
void replaceSpace(char *str,int length) {
    int spaceCount = 0;
    for (int i = 0; i < length; ++i) {
        if (*(str+i) == ' ') {
            spaceCount++;
        }
    }
    
    str[length+2*spaceCount] = '\0';
    
    for (int i = length-1; i >= 0; --i) {
        if (str[i] != ' ') {
            str[i+2*spaceCount] = str[i];
        } else {
            spaceCount--;
            str[i+2*spaceCount] = '%';
            str[i+2*spaceCount+1] = '2';
            str[i+2*spaceCount+2] = '0';
        }
    }
}
