#include "easyfind.hpp"

#include <vector>
#include <list>

int main()
{
    std::vector<int> num;
    num.push_back(10);
    num.push_back(20);
    num.push_back(30);
    num.push_back(90);

    std::list<int> lt;
    lt.push_back(101);
    lt.push_back(201);
    lt.push_back(301);
    lt.push_back(96);
    try
    {
        std::cout << "Found = " << easyfind(num, 20) << std::endl;

        std::cout << "Found = " << easyfind(num,40) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "----------------------------------\n";

    try
    {
        std::cout << "Found = " << easyfind(lt, 201) << std::endl;
        std::cout << "Found = " << easyfind(lt,40) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "----------------------------------\n";
    
    std::vector<int> vect;
    for (int i = 0; i < 10; i++)
        vect.push_back(i+1);
    const std::vector<int> v(vect);

    try
    {
        std::cout << "Found : " << easyfind(v, 6) << std::endl;
        std::cout << "Found : " << easyfind(v, 12) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}