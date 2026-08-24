#include "Animal.hpp"

Animal::Animal()
{
    type = "X";
    std::cout << "Animal Default constructor called\n";
}

Animal::Animal(const Animal& other)
{
    type = other.type;
    std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        type = other.type;
    std::cout << "Animal copy assignment operator called\n";
    return (*this);
}

std::string Animal::getType() const
{
    return (type);
}

void Animal::makeSound() const
{
    std::cout << "sound\n";
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called\n";
}