#include <iostream>
#include "Dog.hpp"
Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}
Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}
Dog &Dog::operator=(const Dog &other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
}
void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}