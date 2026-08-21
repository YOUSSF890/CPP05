#include "Base.hpp"

Base * generate(void)
{
    int n;
    std::srand(time(NULL));
    n = std::rand() % 3;

    if(n == 0)
    {
        return (new A);
    }
    else if(n == 1)
    {
        return(new B);
    }
    else if(n == 2)
    {
        return (new C);
    }
    return(NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "bad type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {}

    try
    {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {}

    try
    {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {}

    std::cout << "bad type" << std::endl;
}

Base::~Base()
{
}
