#include "Span.hpp"
#include <limits.h>

int main()
{
    try
    {
        std::vector<int> v;
        
        Span sp(15);
        Span sp1(15);
        sp = sp;
        sp.addNumber(2147483647);
        sp.addNumber(-2147483648);
        sp.addNumber(0);

        sp1.addNumbers(v.begin(), v.end());
        
        const std::vector<int> a(v);
        sp.addNumbers(a.begin(), a.end());

        std::cout << "shortestSpan = " << sp.shortestSpan() << "\n";
        std::cout << "longestSpan = " << sp.longestSpan() << "\n";

        std::cout << "shortestSpan = " << sp1.shortestSpan() << "\n";
        std::cout << "longestSpan = " << sp1.longestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "-------------------------------------\n";
    
    try
    {
        Span sp(10000);

        for (int i = 0; i < 10000; ++i)
            sp.addNumber(i);

        std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}
