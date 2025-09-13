#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
int main()
{
    std::cout << "--- Animal/Dog/Cat tests ---" << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    const Dog omar;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    std::cout << "=================Deleting all...==========" << std::endl;
    delete meta;
    delete j;
    delete i;
    std::cout << "\n\n\n\n\n--- WrongAnimal/WrongCat tests ---" << std::endl;
    const WrongAnimal *wmeta = new WrongAnimal();
    const WrongAnimal *wi = new WrongCat();
    std::cout << wi->getType() << " " << std::endl;
    wi->makeSound();
    wmeta->makeSound();
    delete wmeta;
    delete wi;

    std::cout << "\n\n\n\nDirect WrongCat object:" << std::endl;
    WrongCat directWrongCat;
    directWrongCat.makeSound(); // Should output WrongCat sound
    std::cout << "=================start Distructor Stack==========" << std::endl;
    return 0;
}