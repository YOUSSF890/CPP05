#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(737);
    mstack.push(8);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "-------------------------------------\n";
    MutantStack<int>::const_iterator it1 = mstack.cbegin();
    MutantStack<int>::const_iterator it2 = mstack.cend();

    while (it1 != it2)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    
    std::cout << "-------------------------------------\n";
    MutantStack<int,std::list<int> > stack11;
    stack11.push(50);

    stack11.push(170);
    std::cout << stack11.top() << std::endl;
    stack11.pop();
    std::cout << stack11.size() << std::endl;
    stack11.push(30);
    stack11.push(70);
    stack11.push(80);

    MutantStack<int, std::list<int> >::reverse_iterator it3 = stack11.rbegin();
    MutantStack<int, std::list<int> >::reverse_iterator it4 = stack11.rend();

    MutantStack<int, std::list<int> >::const_reverse_iterator it33 = stack11.crbegin();
    while (it3 != it4)
    {
        std::cout << *it3 << std::endl;
        std::cout << *it33 << std::endl;
        ++it3;
        ++it33;
    }

    return 0;
}

