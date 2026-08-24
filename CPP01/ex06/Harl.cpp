#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "[ DEBUG ]\n" <<"I love having extra dinde for my 7XL-double-cheese-triple\
-pickle-specialketchup burger.\nI really do!\n\n";
}

void Harl::info()
{
    std::cout << "[ INFO ]\n" << "I cannot believe adding extra dinde costs more money.\nYou didn’t put\
enough dinde in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning()
{
    std::cout << "[ WARNING ]\n" << "I think I deserve to have some extra dinde for free.\nI’ve been coming for\
years, whereas you started working here just last month.\n\n";
}

void Harl::error()
{
    std::cout << "[ ERROR ]\n" << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level)
{

    const std::string av[]   = {"DEBUG","INFO","WARNING","ERROR"};
    int     index   = -1;
    int     i       = 0;

    while(i < 4)
    {
        if (level == av[i])
            index = i;
        i++;
    }

    switch(index)
    {
        case 0:  
            debug();
            // fallthrough
        case 1:
            info();
            // fallthrough
        case 2:
            warning();
            // fallthrough
        case 3:
            error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }

}