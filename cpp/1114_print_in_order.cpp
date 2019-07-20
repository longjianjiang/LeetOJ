
// 三个方法，三个线程按不同的顺序进行调用，要求打印的内容始终是123；
// 加锁进行同步，保证123依次执行即可；
// 这里使用cv进行同步；
class Foo {
private:
	std::mutex _mutex;
	std::condition_variable _cond;
	int _order = 0;

public:
    Foo() {
    }

    void first(function<void()> printFirst) {
        printFirst();

		_order = 1;

		_cond.notify_all();
    }

    void second(function<void()> printSecond) {
		{
			std::unique_lock<std::mutex> lock(_mutex);
			_cond.wait(lock, [this](){ return _order == 1;});

			printSecond();
			_order = 2;
		}

		_cond.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock(_mutex);
		_cond.wait(lock, [this](){ return _order == 2;});

        printThird();
    }
};

class Foo {
private:
	std::mutex m1, m2;

public:
    Foo() {
		m1.lock();
		m2.lock();
    }

    void first(function<void()> printFirst) {
        printFirst();

		m1.unlock();
    }

    void second(function<void()> printSecond) {
		m1.lock();
        printSecond();
		m1.unlock();
		m2.unlock();
    }

    void third(function<void()> printThird) {
		m2.lock();
        printThird();
		m2.unlock();
    }
};
