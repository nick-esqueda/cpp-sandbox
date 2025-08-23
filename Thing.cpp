//
// Created by Nick Esqueda on 8/16/25.
//

#include "Thing.h"

#include <iostream>

// "Initializer List" - after the ":" and before "{"
// runs before the constructor and initializes the instance variables
// more efficient than assigning them in the constructor
// also required for `const` members regardless.
Thing::Thing() : m_num(0), m_is_bool(true) {
  std::cout << "Thing() default constructor invoked" << std::endl;
}

Thing::Thing(const int m_num, const bool m_is_bool)
    : m_num(m_num), m_is_bool(m_is_bool) {
  std::cout << "Thing() parameterized constructor invoked" << std::endl;
}

void Thing::set_num(const int num) { m_num = num; }

void Thing::set_is_bool(const bool boolean) { m_is_bool = boolean; }

// `[[nodiscard]]` tells the compiler to warn callers that don't use the return
// value on the method it's helps emphasize that not using the return value
// would be a programming error/mistake
// `[[nodiscard]]` is controversial - some prefer not to litter their code base
// with it
[[nodiscard]] std::string Thing::to_string() const {
  return "Thing(m_num=" + std::to_string(m_num) +
         ", m_is_bool=" + std::to_string(m_is_bool) + ");";
}
// `const` in the method signature specifies that the method does modify object
// state (i.e. read-only). if a variable of type `Thing` is declared with
// `const`, then ONLY `const` methods can be called. basically, it helps ensure
// the object isn't mutated when `const Thing thing;` is used
