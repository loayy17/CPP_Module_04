#include "WrongCat.hpp"
WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat constructed" << std::endl;
}
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copied" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& other) {
    WrongAnimal::operator=(other);
    return *this;
}
WrongCat::~WrongCat() {
    std::cout << "WrongCat destructed" << std::endl;
}
void WrongCat::makeSound() const {
    std::cout << "Meow (WrongCat) IAm cat" << std::endl;
}
