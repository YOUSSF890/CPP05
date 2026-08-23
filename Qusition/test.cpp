#include "test.hpp"



int main()
{
    Dog<> obj(10.5);
    Dog<std::string> obj2("youssef");
    std::cout << "T = " << obj.value << std::endl;
    std::cout << "T = " << obj2.value << std::endl;
    std::cout << "T = " << ::max<>(10.2) << std::endl;
}