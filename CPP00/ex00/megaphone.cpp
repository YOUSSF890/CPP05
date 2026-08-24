#include <iostream>

int main(int ac, char *av[])
{
    int     i;
    int     a;
    std::string str;
 
    i = 0;
    a = 1;
    if (ac == 1)
        return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
    while (a < ac)
    {
        i = 0;
        while (av[a][i])
        {
            if (islower(av[a][i]))
                av[a][i] = toupper(av[a][i]);
            i++;
        }
        str  += av[a];
        a++;
    }
    std::cout << str << std::endl;
    return (0);
}