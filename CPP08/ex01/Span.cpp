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

void Span::addNumbers(std::vector<int>::const_iterator itB, std::vector<int>::const_iterator itE)
{
    if (itE - itB > N - Current_elements)
        throw std::runtime_error("error in size elements");
    while (itB != itE)
    {
        addNumber(*itB);
        ++itB;
    }
}

long Span::shortestSpan()
{
    if (ptr.size() <= 1)
        throw std::runtime_error("error in shortestSpan\n");
    std::vector<int>::iterator it = ptr.begin();
    std::sort(it, ptr.end());
    long shortest = static_cast<long>(*(it + 1)) - static_cast<long>(*it);
    ++it;
    while(it + 1 != ptr.end())
    {
        if (*(it + 1) - *it < shortest)
            shortest = static_cast<long>(*(it + 1)) - static_cast<long>(*it);
        ++it;
    }
    return(shortest);
}

long Span::longestSpan()
{
    if (ptr.size() <= 1)
        throw std::runtime_error("error in longestSpan\n");
    std::vector<int>::iterator it = ptr.begin();
    std::sort(it ,ptr.end());
    // std::cout << "static_cast<long>(*(it + ptr.size() - 1)) = " << static_cast<long>(*(it + ptr.size() - 1)) << std::endl;
    // std::cout << ""<< *it << std::endl;
    long shortest = static_cast<long>(*(it + ptr.size() - 1)) - static_cast<long>(*it);
    // std::cout << " oo = "<<shortest << std::endl;
    // int shortest = *(it + ptr.size() - 1) - *it;
    return (shortest);
}