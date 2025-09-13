#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  std::cout << "=== Required Test ===" << std::endl;
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter *me = new Character("me");
  AMateria *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter *bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;

  std::cout << "\n=== Additional Tests ===" << std::endl;

  std::cout << "\n--- Test 1: Full inventory ---" << std::endl;
  Character *hero = new Character("hero");
  hero->equip(new Ice());
  hero->equip(new Cure());
  hero->equip(new Ice());
  hero->equip(new Cure());
  hero->equip(new Ice()); // Should not equip (inventory full)

  std::cout << "\n--- Test 2: Unequip and use ---" << std::endl;
  Character *villain = new Character("villain");
  hero->use(0, *villain);
  hero->unequip(0);       // Remove first materia
  hero->use(0, *villain); // Should not work (slot empty)
  hero->use(1, *villain); // Should work

  std::cout << "\n--- Test 3: Deep copy test ---" << std::endl;
  Character *copy = new Character(*hero);
  copy->use(1, *villain);

  std::cout << "\n--- Test 4: Unknown materia type ---" << std::endl;
  MateriaSource *newSrc = new MateriaSource();
  newSrc->learnMateria(new Ice());
  AMateria *unknown = newSrc->createMateria("fire"); // Should return 0
  if (unknown == 0)
    std::cout << "Unknown materia type correctly returned 0" << std::endl;

  std::cout << "\n--- Test 5: MateriaSource full capacity ---" << std::endl;
  newSrc->learnMateria(new Cure());
  newSrc->learnMateria(new Ice());
  newSrc->learnMateria(new Cure());
  newSrc->learnMateria(new Ice());  // Should still learn (4th slot)
  newSrc->learnMateria(new Cure()); // Should not learn (full)

  delete hero;
  delete villain;
  delete copy;
  delete newSrc;

  return 0;
}
