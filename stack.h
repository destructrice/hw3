#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
 private:
    std::vector<T> items;   
};
template <typename T>
Stack<T>::Stack(){
    items = new std::vector<T>;
}
template <typename T>
Stack<T>::~Stack(){
    items.clear();
    delete items;
}
template<typename T>
void Stack<T>::push (T const& item)
{
    items.push_back(item);
}
template<typename T>
void Stack<T>::pop()
{
    assert(!items.empty());
    items.pop_back();
}
template<typename T>
T const& Stack<T>::top() const
{
    assert(!items.empty());
    return items.back();
}
template<typename T>
size_t Stack<T>::size() const{
    return items.size();
}

#endif