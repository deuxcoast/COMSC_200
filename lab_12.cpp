#include <iostream>
#include <ostream>
#include <stack>

template <typename T>
class Queue {
   private:
    std::stack<T> input;
    std::stack<T> output;

   public:
    Queue() {}

    void push(T x) { input.push(x); }

    T pop() {
        peek();
        int val = output.top();
        output.pop();
        return val;
    }

    T peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty() { return input.empty() && output.empty(); }
};

int main() {
    Queue<int> que{};

    que.push(10);
    que.push(20);
    que.push(30);
    std::cout << que.pop() << std::endl;
    std::cout << que.empty() << std::endl;
    std::cout << que.pop() << std::endl;
    std::cout << que.pop() << std::endl;
    return 0;
}
