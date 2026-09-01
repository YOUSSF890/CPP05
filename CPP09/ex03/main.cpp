#include "PmergeMe.hpp"



int main(int ac,char *av[])
{
    if (ac != 2)
        return (std::cout << "Error : " << std::endl, 1);
    std::vector<int> array;
    std::stringstream ss(av[1]);
    int nb;

    while(ss >> nb)
    {
        if (ss.fail())
            return (std::cout << "Error : " << std::endl, 1);
        array.push_back(nb);
    }

    sortVector(array);

    // for (size_t i = 0; i < array.size(); i++)
	// 	std::cout << array[i] << " " ;
}