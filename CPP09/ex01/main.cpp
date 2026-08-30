#include "RPN.hpp"




int main(int ac, char *av[])
{
    try
    {
        RPN obj;
        if (ac != 2)
            throw std::runtime_error("Error : input paramiter");
        obj.str = av[1];
        obj.StoreElement();
        std::cout << obj.stack.top() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}