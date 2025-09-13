#include <iostream>
#include "Dog.hpp"
Dog::Dog() : Animal()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}
Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}
Dog &Dog::operator=(const Dog &other)
{
    if(this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}
void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}

Brain *Dog::getBrain() const {
    return brain;
}