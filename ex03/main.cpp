#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  std::cout << "=== Required Test ===" << std::endl;
  IMateriaSource *src = new MateriaSource();
  AMateria *ice_to_learn = new Ice();
  AMateria *cure_to_learn = new Cure();
  src->learnMateria(ice_to_learn);
  src->learnMateria(cure_to_learn);
  delete ice_to_learn;
  delete cure_to_learn;

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
  AMateria *ice1 = new Ice();
  AMateria *cure1 = new Cure();
  AMateria *ice2 = new Ice();
  AMateria *cure2 = new Cure();
  AMateria *ice3 = new Ice(); // This won't be equipped (inventory full)
  hero->equip(ice1);
  hero->equip(cure1);
  hero->equip(ice2);
  hero->equip(cure2);
  hero->equip(ice3); // Should not equip (inventory full)
  delete ice3;       // Clean up the unequipped materia

  std::cout << "\n--- Test 2: Use tests ---" << std::endl;
  Character *villain = new Character("villain");
  hero->use(0, *villain);  // Should work
  hero->use(1, *villain);  // Should work
  hero->use(10, *villain); // Should not work (out of bounds)
  hero->use(-1, *villain); // Should not work (negative index)

  std::cout << "\n--- Test 3: Deep copy test ---" << std::endl;
  Character *copy = new Character(*hero);
  copy->use(1, *villain);

  std::cout << "\n--- Test 4: Unknown materia type ---" << std::endl;
  MateriaSource *newSrc = new MateriaSource();
  AMateria *iceForLearning = new Ice();
  newSrc->learnMateria(iceForLearning);
  delete iceForLearning; // Clean up original after learning
  AMateria *unknown = newSrc->createMateria("fire"); // Should return 0
  if (unknown == 0)
    std::cout << "Unknown materia type correctly returned 0" << std::endl;

  std::cout << "\n--- Test 5: MateriaSource full capacity ---" << std::endl;
  AMateria *cure3 = new Cure();
  AMateria *ice4 = new Ice();
  AMateria *cure4 = new Cure();
  AMateria *ice5 = new Ice();
  AMateria *cure5 = new Cure(); // This won't be learned (full)
  newSrc->learnMateria(cure3);
  newSrc->learnMateria(ice4);
  newSrc->learnMateria(cure4);
  newSrc->learnMateria(ice5);  // Should still learn (4th slot)
  newSrc->learnMateria(cure5); // Should not learn (full)
  delete cure3;
  delete ice4;
  delete cure4;
  delete ice5;
  delete cure5; // Clean up all originals

  delete hero;
  delete villain;
  delete copy;
  delete newSrc;

  return 0;
}