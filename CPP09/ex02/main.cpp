#include "PmergeMe.hpp"

int main(int ac,char *av[])
{
    if (ac < 2)
        return (std::cout << "Error" << std::endl, 1);
    
    std::vector<int>    array;
    std::deque<int>     arr;
    std::string         str;
    long                 nb;
    int                 count = 0;
    
    for (int i = 1; i < ac; i++)
    {
        str = av[i];
        for (size_t j = 0; j < str.size(); j++)
        {
            if (!isdigit(str[j]) && str[j] != ' ')
                return (std::cout << "Error" << std::endl, 1);
            if (isdigit(str[j]))
                count++;
            else
            {
                if (count > 10)
                    return (std::cout << "Error" << std::endl, 1);
                count = 0;
            }
            
        }
    }

    for (int i = 1; i < ac; i++)
    {
        std::stringstream ss(av[i]);
        while(ss >> nb)
        {
            std::vector<int>::iterator it = std::find(array.begin(),array.end(),nb);
            if (ss.fail() || nb > INT_MAX || it != array.end())
                return (std::cout << "Error" << std::endl, 1);
            array.push_back(nb);
            arr.push_back(nb);
        }
    }
    if (array.size() == 0)
        return (std::cout << "Error" << std::endl, 1);

    // ------------------ print Before -----------------------

    std::cout << "Before:";
    for (size_t i = 0; i < array.size();i++)
    {
        std::cout << " " << array[i];
    }
    std::cout << std::endl;

    clock_t start = clock();
    sortVector(array);
    clock_t end = clock();

    // ------------------ print After -----------------------

    std::cout << "After:";
    for (size_t i = 0; i < array.size();i++)
    {
        std::cout << " " << array[i];
    }
    std::cout << std::endl;

    // ------------------ print time vector -----------------------

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << array.size() << " elements with std::vector : " << static_cast<double>(end - start) << " us" << std::endl;

    start = clock();
    sortDeque(arr);
    end = clock();

    // ------------------ print time deque -----------------------

    std::cout << "Time to process a range of " << arr.size() << " elements with std::deque : " << static_cast<double>(end - start) << " us" << std::endl;

}