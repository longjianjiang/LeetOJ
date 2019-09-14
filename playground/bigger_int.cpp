#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 不用比较运算符，返回较大的那个

int is_positive(int a) {
    int count = 0;
    while(a){
        a = a & (a - 1);
        count++;
    }
    return count == 0;
}

int bigger(int a, int b) {
    int sign_bit = 1 << 31;
    int sign_a = is_positive(a & sign_bit), sign_b = is_positive(b & sign_bit);
    
    if (sign_a ^ sign_b) {
        if (sign_a & 1) {
            return a;
        } else {
            return b;
        }
    } else {
        if (!sign_a) {
            a = (~a + 1);
            b = (~b + 1);
        }
        for (int i = 30; i >= 0; --i) {
            int bit = 1 << i;
            int bit_a = a & bit, bit_b = b & bit;
            if (!(bit_a ^ bit_b)) { continue; }
            
            if (sign_a & 1) { // positive
                if (bit_a & bit) {
                    return a;
                } else {
                    return b;
                }
            } else { // negative
                if (bit_a & bit) {
                    return -b;
                } else {
                    return -a;
                }
            }
        }
    }
    
    return a; // a == b
}

void unit_test() {
	vector<vector<int>> list = {{INT_MIN, INT_MAX}, {5, 7}, {-5, -7}, {7, -5}, {5, -7}};
	for (auto nums: list) {
		cout << bigger(nums[0], nums[1]) << endl;
	}
}

int main() {
	unit_test();
	return 0;
}
