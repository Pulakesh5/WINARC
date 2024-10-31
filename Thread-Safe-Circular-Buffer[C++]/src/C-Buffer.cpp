#include "C-Buffer.hpp"

template <typename T>
int CircularBuffer<T>::rptr = -1;
template <typename T>
int CircularBuffer<T>::fptr = -1;

template <typename T>
CircularBuffer<T>::CircularBuffer(size_t n)
{
    CircularBuffer<T>::fptr = -1;
    CircularBuffer<T>::rptr = -1;
    CAPACITY = n;
    buffer.reserve(n);
}

template <typename T>
CircularBuffer<T>::~CircularBuffer()
{
    buffer.clear();
    // cout << "Circular Buffer Destroyed\n";
}

template <typename T>
void CircularBuffer<T>::push(T item)
{
    try
    {
        if ((rptr + 1) % CAPACITY == fptr)
        {
            throw runtime_error("Beyond Buffer Capacity");
        }
        if (fptr == -1)
            fptr = 0;
        rptr = (rptr + 1) % CAPACITY;
        buffer[rptr] = item;
        cout << "Pushed \033[32m" << item << "\033[0m\n";
    }
    catch (const exception &e)
    {
        cerr << "Exception: \033[31m" << e.what() << "\033[0m\n";
    }
}
template <typename T>
T CircularBuffer<T>::pop()
{
    try
    {
        if (fptr == -1)
        {
            throw runtime_error("You should take my life. Thats's all I've got.");
        }
        T returnItem = buffer[fptr];
        if (fptr == rptr)
        {
            fptr = -1;
            rptr = -1;
        }
        else
        {
            fptr = (fptr + 1) % CAPACITY;
        }
        cout << "Popped \033[31m" << returnItem << "\033[0m\n";
        return returnItem;
    }
    catch (const exception &e)
    {
        cerr << "Exception: \033[31m" << e.what() << "\033[0m\n";
        return T();
    }
}

// utility function to_string for ease of printing content of C-Buffer
template <typename T>
string CircularBuffer<T>::to_string()
{
    stringstream os;
    int r_end = rptr;
    if (r_end < fptr)
        r_end = CAPACITY - 1;
    // os << fptr << "\n"
    //    << rptr << "\n"
    //    << r_end << endl;

    os << "Buffer :[ ";

    for (size_t i = fptr; i <= r_end; i++)
        os
            << buffer[i] << " ";

    if (rptr < fptr)
    {
        for (size_t i = 0; i <= rptr; i++)
            os << buffer[i] << " ";
    }
    os << "]";
    return os.str();
}
