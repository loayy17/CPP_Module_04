#include "Cat.hpp"
Cat::Cat(): Animal() 
{
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() 
{
        std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if(this != &other)
    {
        type = other.type;
    }
    return *this;
}

Cat::Cat(const Cat &other) : Animal(other) 
{
    std::cout << "Cat copy constructor called" << std::endl;
}
void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}