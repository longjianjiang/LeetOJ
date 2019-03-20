#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <cassert>

using namespace std;

// 给定一个数组，将数组的元素取反K次，每次可以取反相同的元素，返回K次取反后数组和的最大值
// 想到使用数组建一个最小堆，每次取堆顶元素，然后将其出堆，将其相反数进堆，循环K次即可

int largestSumAfterNegations(vector<int>& A, int K) {
    int sum = accumulate(A.begin(), A.end(), 0);
    priority_queue<int, vector<int>, greater<int>> pq{A.begin(), A.end()};
    while (K) {
        auto top = pq.top();
        sum -= 2*top;
        pq.pop();
        pq.push(-top);

        --K;
    }
    return sum;
}

void unitTest() {
    vector<int> v1{4, 2, 3};
    assert(largestSumAfterNegations(v1, 1) == 5);

    vector<int> v2{3, -1, 0, 2};
    assert(largestSumAfterNegations(v2, 3) == 6);

    vector<int> v3{2, -3, -1, 5, -4};
    assert(largestSumAfterNegations(v3, 2) == 13);

    vector<int> v4{5, 6, 9, -3, 3};
    assert(largestSumAfterNegations(v4, 2) == 20);
}

int main(int argc, const char * argv[]) {

    unitTest();

    return 0;
}

