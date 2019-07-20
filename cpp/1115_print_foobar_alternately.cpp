// 两个线程分别输出foo, bar, 要求结果必须是foobarfoobar这样。
// [ref](https://leetcode.com/problems/print-foobar-alternately/discuss/333365/Why-is-atomic-slower-than-mutex)
class FooBar {
private:
    int n;
    std::atomic_flag new_time = ATOMIC_FLAG_INIT;
    std::atomic<bool> step_two = ATOMIC_VAR_INIT(false);

public:
    FooBar() = default;
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            while (new_time.test_and_set(std::memory_order_relaxed)) {}

            printFoo();

            step_two.store(true, std::memory_order_relaxed);
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            while (step_two.load(std::memory_order_relaxed) == false) {}

            printBar();

            step_two.store(false, std::memory_order_relaxed);
            new_time.clear(std::memory_order_relaxed);
        }
    }
};

class FooBarAtomic {
private:
	int n;
	std::atomic<bool> ai;

public:
	FooBarAtomic(int n) {
		this->n = n;
        ai.store(true, std::memory_order_relaxed);
	}

    void foo(function<void()> printFoo) {
		while (ai == false) { std::this_thread::yield(); }

		printFoo();

        ai.store(true, std::memory_order_relaxed);
	}

    void bar(function<void()> printBar) {
		while (ai == true) { std::this_thread::yield(); }

		printBar();

        ai.store(false, std::memory_order_relaxed);
	}
};

class FooBar_Lock {
private:
    int n;
    std::mutex m1, m2;

public:
    FooBar_Lock(int n) {
        this->n = n;

        m1.lock();
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            m2.lock();

            printFoo();

            m1.unlock();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            m1.lock();

            printBar();

            m2.unlock();

        }
    }
};
