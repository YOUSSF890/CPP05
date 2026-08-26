#include "Span.hpp"


Span::Span()
{
    N = 0;
    Current_elements = 0;
}

Span::Span(unsigned int Capacity)
{
    N = Capacity;
    Current_elements = 0;
}

Span::Span(const Span &other)
{
    N = other.N;
    Current_elements = other.Current_elements;
    ptr = other.ptr;
}

Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        N = other.N;
        Current_elements = other.Current_elements;
        ptr = other.ptr;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int nb)
{
    if (Current_elements + 1 > N)
        throw std::runtime_error("error in Current_elements");
    ptr.push_back(nb);
    Current_elements++;
}

void Span::addNumbers(std::vector<int>::iterator itB, std::vector<int>::iterator itE)
{
    while (itB != itE)
    {
        addNumber(*itB);
        ++itB;
    }
}

int Span::shortestSpan()
{
    if (ptr.size() <= 1)
        throw std::runtime_error("error in shortestSpan\n");
    std::vector<int>::iterator it = ptr.begin();
    std::sort(it, ptr.end());
    int shortest = *(it + 1) - *it;
    ++it;
    while(it + 1 != ptr.end())
    {
        if (*(it + 1) - *it < shortest)//&& *(it + 1) - *it >= 0
            shortest = *(it + 1) - *it;
        ++it;
    }
    return(shortest);
}

int Span::longestSpan()
{
    if (ptr.size() <= 1)
        throw std::runtime_error("error in longestSpan\n");
    std::vector<int>::iterator it = ptr.begin();
    std::sort(it ,ptr.end());

    return (*(it + ptr.size() - 1) - *it);
}