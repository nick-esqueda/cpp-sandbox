//
// Created by Nick Esqueda on 8/24/25.
//

#include <iostream>

/**
 * This file shows why we must use pointers (or references) for polymorphism.
 */

struct Animal {
  virtual ~Animal() = default;
  virtual void speak() = 0;
};

// Reminder: structs have public members/methods AND inheritance by default.
// i.e. Equivalent to "struct Dog : public Animal"
struct Dog final : Animal {
  void speak() override { std::cout << "Woof woof\n"; }
};

struct Cat final : Animal {
  void speak() override { std::cout << "Meow\n"; }
};

/**
 * PROBLEM:
 * This function throws a compile error:
 * "Struct Animal is abstract: function void Animal::speak() is pure virtual"
 * And a warning:
 * "Possibly unintended object slicing: struct 'Animal' is value-initialized
 * from derived struct 'Dog'"
 *
 * REASON:
 * We are returning by value (copy), i.e. "Copy this Dog into an Animal object".
 * So, what makes the Dog a Dog gets "sliced" off in order to force the value
 * into an Animal object. Moreover, Animal is an abstract class, so it can't
 * even be instantiated.
 *
 * SOLUTION:
 * "Indirection preserves polymorphism"
 * You need indirection if you want to treat structs/classes polymorphically.
 * Indirection = accessing a value _through_ something else (ref/ptr/etc.)
 */
// Animal make_animal_value(const bool is_dog) {
//   if (is_dog) {
//     return Dog{};
//   }
//   return Cat{};
// }

/**
 * Dynamically allocating memory for the desired return type fixes the issue.
 * We can still say the return type is an "Animal" without having to slice the
 * Dog features to make an Animal, or attempting to construct an abstract Animal
 * object, because the pointer points to an existing Dog/Cat stored in memory
 * (which "IS" an Animal).
 *
 * DEMONSTRATION ONLY: use a smart pointer instead.
 */
Animal *make_animal_raw_ptr(const bool is_dog) {
  if (is_dog) {
    return new Dog{};
  }
  return new Cat{};
}

std::unique_ptr<Animal> make_animal_smart_ptr(const bool is_dog) {
  if (is_dog) {
    return std::make_unique<Dog>();
  }
  return std::make_unique<Cat>();
}

int main() {
  // Slicing issue demonstration:
  Dog dog;
  // Animal a = dog; // Compile error since Animal is abstract
  // a.speak();

  // No slicing occurs here since the Dog is referred to by reference
  Animal &dog_ref = dog;
  dog_ref.speak(); // Calls `dog.speak()` normally

  // Runtime polymorphism example - raw pointer (BAD PRACTICE)
  Animal *a = make_animal_raw_ptr(false);
  a->speak();
  delete a;

  auto a2 = make_animal_smart_ptr(false);
  a2->speak();

  return 0;
}
