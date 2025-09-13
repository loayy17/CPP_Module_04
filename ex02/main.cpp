#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>
int main() 
{
    std::cout << "=== Testing Abstract Animal Class ===" << std::endl;
    Animal *animals[6];
    std::cout << "Creating 3 Dogs..." << std::endl;
    for (int i = 0; i < 3; ++i)
        animals[i] = new Dog();
    std::cout << "Creating 3 Cats..." << std::endl;
    for (int i = 3; i < 6; ++i)
        animals[i] = new Cat();
    
    std::cout << "Making sounds..." << std::endl;
    for (int i = 0; i < 6; ++i)
        animals[i]->makeSound();
        
    std::cout << "Destructing all..." << std::endl;
    for (int i = 0; i < 6; ++i)
        delete animals[i];
// Animal* animal = new Animal(); // not allowed because there is pure virtual function
    std::cout << "================= DEEP COPY CAT TEST ========" << std::endl;
    Cat *originalCat = new Cat();
    originalCat->getBrain()->setIdea(0, "From Original: Chase the mouse first");
    originalCat->getBrain()->setIdea(1, "From Original: Chase the mouse second");
    originalCat->getBrain()->setIdea(2, "From Original: Chase the mouse third");
    originalCat->getBrain()->setIdea(3, "From Original: Chase the mouse fourth");
    originalCat->getBrain()->setIdea(4, "From Original: Chase the mouse fifth");
    originalCat->getBrain()->setIdea(5, "From Original: Chase the mouse sixth");
    originalCat->getBrain()->setIdea(6, "From Original: Chase the mouse seventh");
    Cat *copyCat = new Cat(*originalCat);
    copyCat->getBrain()->setIdea(4, "From Copy: Sleep all day");
    copyCat->getBrain()->setIdea(10, "From Copy: Sleep all night");
    copyCat->getBrain()->setIdea(9, "From Copy: Sleep in the afternoon");
    copyCat->getBrain()->setIdea(3, "From Copy: Sleep on the couch");
    copyCat->getBrain()->setIdea(4, "From Copy: Sleep on the bed");
    Cat *assignEqualCat = new Cat();
    *assignEqualCat = *originalCat;
    assignEqualCat->getBrain()->setIdea(0, "From assignment: Play with yarn");
    for(int i = 0; i < 11; i++)
        std::cout << "Original Cat Idea[" << i << "]: " << originalCat->getBrain()->getIdea(i) << std::endl;
    std::cout << "====================================================== " << std::endl;
    for(int i = 0; i < 11; i++)
        std::cout << "Copied Cat Idea[" << i << "]: " << copyCat->getBrain()->getIdea(i) << std::endl;
    std::cout << "====================================================== " << std::endl;
    for (int i = 0; i < 11; i++)
        std::cout << "Assignment Cat IDeas[" << i << "]: " << assignEqualCat->getBrain()->getIdea(i) << std::endl;
    std::cout << "====================================================== " << std::endl;
    std::cout << "================= End of Deep Copy Test ========" << std::endl;

    delete originalCat;
    delete copyCat;
    delete assignEqualCat;
    return 0;
}