#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class Stack : public std::vector<T>
{
public:
    Stack() = default;
    ~Stack() = default;

    // returns true if stack is empty
    bool empty() const {
        return this->size() == 0;
    }

    // returns the size of the stack
    size_t size() const {
        return this->std::vector<T>::size();
    }

    // "pushes" an element onto the stack
    void push(const T& item) {
        this->push_back(item);  // Using vector's push_back for O(1) push
    }

    // pops the top element from the stack. throws stack underflow_error if empty.
    void pop() {
        if (empty()) {
            throw std::underflow_error("Stack is empty, cannot pop");
        }
        this->pop_back();  // Using vector's pop_back for O(1) pop
    }

    // returns the top element. throws stack underflow_error if empty.
    const T& top() const {
        if (empty()) {
            throw std::underflow_error("Stack is empty, cannot access top");
        }
        return this->back();  
    }
};

#endif
