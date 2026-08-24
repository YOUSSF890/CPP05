#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat"; 
    std::cout << "Cat Default constructor called\n";
}

Cat::Cat(const Cat& other): Animal(other)
{
    std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Cat Copy assignment operator called\n";
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "meow!!\n";
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called\n";
}