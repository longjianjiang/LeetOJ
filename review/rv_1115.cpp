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

class FooBar {
private:
    int n;
	int _order;
	std::mutex _mutex;
	std::condition_variable _cond;

public:
    FooBar(int n) {
        this->n = n;
		this->_order = 0;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(_mutex);
			_cond.wait(lock, [this](){ return _order == 0;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            _order = 1;
            _cond.notify_all();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(_mutex);
			_cond.wait(lock, [this](){ return _order == 1;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            _order = 0;
            _cond.notify_all();
        }
    }
};
