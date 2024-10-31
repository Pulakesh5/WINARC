#include <iostream>
#include "src/C-Buffer.cpp"

using namespace std;

int main()
{
    CircularBuffer<int> cb(5);
    cb.push(1);
    cb.push(7);
    cb.push(2);
    cb.push(9);
    cout << cb.to_string() << endl;
    int rval = cb.pop();
    cb.push(5);
    cb.push(7);
    cb.push(11);
    cout << cb.to_string() << endl;
}