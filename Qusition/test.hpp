#ifndef TEST_HPP
#define TEST_HPP
#include <iostream>

template <typename T = int>

class Dog
{
    public:
        Dog(T v)
        {
            value = v;
        }
        T value;
};

template <typename T = int>


T max( T a)
{
    return a;
}

#endif