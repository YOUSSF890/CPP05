#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain;
    std::cout << "Cat Default constructor called\n";
}

Cat::Cat(const Cat& other): Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Cat Copy assignment operator called\n";
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "meow!!\n";
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor called\n";
}
