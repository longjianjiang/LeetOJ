#include <queue>
#include <vector>

using namespace std;

// 类似无序数组找中位数是一样的，这里使用priority_queue实现堆的功能，同时最小堆使用存负数来实现，取出的时候取反即可，
// 建两个堆，最大堆和最小堆，将数据拆分位两部分，左边位最大堆，右边位最小堆，同时最小堆的元素要大于最大堆的元素，
// 同时保证最大堆的元素个数大于最小堆的元素个数，所以取中位数，如果最大堆元素个数多，直接返回top，否则两个堆的top相加除2即可。

// 这里主要是存储，主要要保证两点，最小堆的元素要大于最大堆的元素，同时最大堆的元素个数要大于最小堆。

class MedianFinder {
private:
	priority_queue<int> _maxHeap, _minHeap;

public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        _maxHeap.push(num);
        _minHeap.push(-_maxHeap.top());
        _maxHeap.pop();
        if (_maxHeap.size() < _minHeap.size()) {
        	_maxHeap.push(-_minHeap.top());
        	_minHeap.pop();
        }
    }
    
    double findMedian() {
        return _maxHeap.size() > _minHeap.size() ? _maxHeap.top() : 0.5 * (_maxHeap.top() - _minHeap.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */