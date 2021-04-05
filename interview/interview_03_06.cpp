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

/*
动物收容所。有家动物收容所只收容狗与猫，且严格遵守“先进先出”的原则。在收养该收容所的动物时，收养人只能收养所有动物中“最老”（由其进入收容所的时间长短而定）的动物，或者可以挑选猫或狗（同时必须收养此类动物中“最老”的）。换言之，收养人不能自由挑选想收养的对象。请创建适用于这个系统的数据结构，实现各种操作方法，比如enqueue、dequeueAny、dequeueDog和dequeueCat。允许使用Java内置的LinkedList数据结构。

enqueue方法有一个animal参数，animal[0]代表动物编号，animal[1]代表动物种类，其中 0 代表猫，1 代表狗。

dequeue*方法返回一个列表[动物编号, 动物种类]，若没有可以收养的动物，则返回[-1,-1]。
*/
// 1> 使用两个队列，存狗和猫； 
class AnimalShelf {
private:
	queue<vector<int>> q0;
	queue<vector<int>> q1;
public:
    AnimalShelf() {

    }

    void enqueue(vector<int> animal) {
		if (animal[1] == 0) {
			q0.push(animal);
		} else {
			q1.push(animal);
		}
    }

    vector<int> dequeueAny() {
		if (q0.empty() && q1.empty()) { return {-1, -1}; }
		if (q0.empty()) { return find(q1); }
		if (q1.empty()) { return find(q0); }

		auto cat = q0.front();
		auto dog = q1.front();
        if (cat[0] < dog[0]) {
            q0.pop();
            return cat;
        } else {
            q1.pop();
            return dog;
        }
    }

    vector<int> dequeueDog() {
		return find(q1);
    }

    vector<int> dequeueCat() {
		return find(q0);
    }

	vector<int> find(queue<vector<int>>& q) {
		if (q.empty()) { return {-1, -1}; }
		auto res = q.front();
		q.pop();
		return res;

	}
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */