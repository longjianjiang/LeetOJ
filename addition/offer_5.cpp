
// 要求使用两个栈来实现队列的Push和Pop操作
// push 时使用stack1存数据，pop时将stack1的数据依次入栈stack2，此时数据就是正常的顺序

class Solution {
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (!stack2.empty()) {
            int num = stack2.top();
            stack2.pop();
            return num;
        }
        int size = (int)stack1.size();
        for (int i = 0; i < size; ++i) {
            int num = stack1.top();
            stack1.pop();
            stack2.push(num);
        }
        int num = stack2.top();
        stack2.pop();
        return num;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};