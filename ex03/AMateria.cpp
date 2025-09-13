#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(AMateria const &other) : _type(other._type) {}

AMateria &AMateria::operator=(AMateria const &other) {
  (void)other;
  return *this;
}

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target) {
  std::cout << "* uses " << _type << " on " << target.getName() << " *"
            << std::endl;
}