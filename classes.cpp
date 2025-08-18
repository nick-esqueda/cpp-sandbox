//
// Created by Nick Esqueda on 8/16/25.
//

#include <iostream>

#include "Thing.h"

int main() {
  // don't have to use `new` to initialize - this will perform stack allocation
  // if you use `new`, the object will be allocated to the heap. (must also use `delete`)
  Thing thing1; // Uses default constructor
  Thing thing2(2, false); // Uses parameterized constructor (initializer list)

  std::cout << "Thing 1: " << thing1.to_string() << std::endl;
  std::cout << "Thing 2: " << thing2.to_string() << std::endl;

  thing1.set_num(4);
  thing1.set_is_bool(false);
  thing2.set_num(4);
  thing2.set_is_bool(false);

  std::cout << "Thing 1: " << thing1.to_string() << std::endl;
  std::cout << "Thing 2: " << thing2.to_string() << std::endl;

  return 0;
}
