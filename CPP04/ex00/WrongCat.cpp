#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat"; 
    std::cout << "WrongCat Default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << "WrongCat Copy assignment operator called\n";
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "meow!!\n";
}


WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called\n";
}