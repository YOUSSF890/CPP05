
#include <iostream>

int main()
{

    int x = 13377;

    int *p = &x;

    char *q = reinterpret_cast<char *>(p);

    std::cout << &q << std::endl;
    std::cout << q[0] << std::endl;
    std::cout << q[1] << std::endl;
    std::cout << q[2] << std::endl;
    std::cout << *q << std::endl;
}