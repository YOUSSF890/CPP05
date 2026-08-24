#include "Harl.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
        return (std::cout << "Enter : DEBUG or INFO or WARNING or ERROR. \n", 1);
    Harl obj;
    obj.complain(av[1]);
}
