#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>


class Span
{
    private:
        unsigned int N;
        unsigned int Current_elements;
        std::vector<int> ptr;
    public:
        Span();
        Span(unsigned int Capacity);
        Span(const Span &other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int nb);
        void addNumbers(std::vector<int>::const_iterator itB, std::vector<int>::const_iterator itE);
        long shortestSpan();
        long longestSpan();
};



#endif