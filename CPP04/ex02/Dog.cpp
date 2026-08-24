#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain;
    std::cout << "Dog Default constructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Dog copy assignment operator called\n";
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "woof!!\n";
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor called\n";
}