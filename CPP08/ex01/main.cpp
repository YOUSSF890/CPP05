#include "Span.hpp"

int main()
{
    try
    {
        std::vector<int> v;
        Span sp(15);
        sp.addNumber(50);
        sp.addNumber(60);
        sp.addNumber(30);
        sp.addNumber(1);
        sp.addNumber(4);
        
        v.push_back(90);
        v.push_back(10);
        v.push_back(38);
        v.push_back(00);
        v.push_back(30);
        v.push_back(56);
        v.push_back(34);
        v.push_back(20);
        v.push_back(0);

        sp.addNumbers(v.begin(), v.end());

        std::cout << "shortestSpan = " << sp.shortestSpan() << "\n";
        std::cout << "longestSpan = " << sp.longestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}
