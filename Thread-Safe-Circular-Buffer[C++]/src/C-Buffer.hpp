#ifndef C_BUFFER_HPP
#define C_BUFFER_HPP

#include <vector>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <concepts>

using namespace std;

template <typename T>
class CircularBuffer
{
public:
    CircularBuffer(size_t n);
    ~CircularBuffer();
    void push(T item);
    T pop();
    string to_string();

private:
    size_t CAPACITY;
    vector<T> buffer;
    static int fptr, rptr;
    std::condition_variable empty, full;
};

#endif // C_BUFFER_HPP