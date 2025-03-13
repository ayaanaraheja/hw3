#include <iostream>
#include "stack.h"

int main() {
    Stack<int> stack;

    try {
        stack.push(10);
        stack.push(20);
        stack.push(30);

        std::cout << "top element: " << stack.top() << std::endl; // output 30
        stack.pop();
        std::cout << "top element post pop: " << stack.top() << std::endl; // output 20
        stack.pop();
        stack.pop();

        stack.pop();
    } catch (const std::underflow_error& e) {
        std::cout << "error: " << e.what() << std::endl;  // output stack underflow error
    }

    return 0;
}
