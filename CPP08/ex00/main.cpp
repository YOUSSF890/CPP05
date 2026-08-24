#include "easyfind.hpp"


int main()
{
    std::vector<int> num;
        num.push_back(10);
        num.push_back(20);
        num.push_back(30);
    try
    {
        std::vector<int>::iterator it = easyfind(num,20);
        std::cout << "Found = " << *it << std::endl;
        it++;
        std::cout << "Found = " << *it << std::endl;


        it = easyfind(num,40);
        std::cout << "Found = " << *it << std::endl;
        
        
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    
}