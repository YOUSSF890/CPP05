#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "I love having extra dinde for my 7XL-double-cheese-triple-pickle\
-specialketchup burger. I really do!\n";
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra dinde costs more money. You didn’t put\
enough dinde in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra dinde for free. I’ve been coming for\
years, whereas you started working here just last month.\n";
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
    int i = 0;
    const std::string av[]   = {"DEBUG","INFO","WARNING","ERROR"};
    void (Harl::*print[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    while(i < 4)
    {
        if (level == av[i])
        {
            (this->*print[i])();
            break ;
        }
        i++;
    }
}