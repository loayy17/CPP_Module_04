#include "WrongAnimal.hpp"
WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructed" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal copied" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) type = other.type;
    return *this;
}
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructed" << std::endl;
}
void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
}
std::string WrongAnimal::getType() const {
    return type;
}
