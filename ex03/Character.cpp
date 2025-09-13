#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>
Character::Character(std::string n) : name(n) {
  for (int i = 0; i < 4; i++) {
    inventory[i] = 0;
  }
}
Character::~Character() {
  for (int i = 0; i < 4; i++) {
    if (inventory[i]) {
      delete inventory[i];
    }
  }
}
Character::Character(const Character &other) : name(other.name) {
  for (int i = 0; i < 4; i++) {
    if (other.inventory[i]) {
      inventory[i] = other.inventory[i]->clone();
    } else {
      inventory[i] = 0;
    }
  }
}
Character &Character::operator=(const Character &other) {
  if (this != &other) {
    name = other.name;
    for (int i = 0; i < 4; i++) {
      if (inventory[i]) {
        delete inventory[i];
      }
      inventory[i] = 0;
    }
    for (int i = 0; i < 4; i++) {
      if (other.inventory[i]) {
        inventory[i] = other.inventory[i]->clone();
      } else {
        inventory[i] = 0;
      }
    }
  }
  return *this;
}
std::string const &Character::getName() const { return name; }
void Character::equip(AMateria *m) {
  for (int i = 0; i < 4; i++) {
    if (!inventory[i]) {
      inventory[i] = m;
      break;
    }
  }
}
void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4) {
    inventory[idx] = 0;
  }
}
void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx < 4 && inventory[idx]) {
    inventory[idx]->use(target);
  }
}
