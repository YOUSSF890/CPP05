#include "Base.hpp"

int main()
{
    A a;
    Base* p = generate();

    std::cout << "Pointer version:" << std::endl;
    identify(p);


    std::cout << "\nReference version:" << std::endl;
    Base& p2 = a;
    identify(p2);

    delete p;
}