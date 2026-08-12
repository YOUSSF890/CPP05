#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <limits>
#include <vector>

class Span{
    private:
        unsigned int N;
        unsigned int Current_elements;
        std::vector<int> ptr;
    public:
        Span(unsigned int Capacity);

        void addNumber(int nb);
        void addNumbers(std::vector<int>::iterator itB, std::vector<int>::iterator itE);
        int shortestSpan();
        int longestSpan();
};



#endif