//
// Created by Nick Esqueda on 8/22/25.
//

#include <iostream>
#include <memory>

/**
 * Smart Pointers
 *
 * WHAT?
 * An offering from the Standard Library that provides RAII to pointers.
 *
 * WHY?
 * With raw pointers, you must manually manage resource acquisition/release (use
 * `new`/`delete`). Smart pointers take that responsibility. The
 * acquisition/release will happen automatically with object
 * creation/destruction. This prevents memory/resource leaks.
 *
 * Ownership = when using `new` to allocate memory, the variable it's assigned
 * to owns that memory. You must `delete <var>`, or it leaks. So, that variable
 * "owns" it. With smart pointers, ownership is explicit and automatic.
 * std::unique_ptr = only ONE possible owner - cannot copy. Will always be
 * cleaned up when the owner reference goes out of scope. std::shared_ptr = can
 * have MANY owners of the object. Gets cleaned up when the LAST reference to
 * the object (owner) is destroyed.
 */

void shared_pointers() {
  std::shared_ptr<int[]> arr1(new int[10]);

  auto arr4 = arr1;
}

void unique_pointers() {
  // Not recommended: Directly calling the constructor
  // Why? Potential memory leak in certain exception scenarios
  const std::unique_ptr<int[]> arr1(new int[10]);
  arr1[0] = 10;

  // Only 1 owner is allowed - hence "unique"
  // auto arr4 = arr1; // Compile error

  std::cout << arr1[0] << std::endl;

  // Recommended: std::make_unique - Factory function that CREATES a unique_ptr
  // Object creation & wrapping is done in one atomic step - safer than direct
  // construction
  const auto arr2 = std::make_unique<int[]>(10);
  arr2[0] = 12;

  std::cout << arr2[0] << std::endl;

  // No memory leak! Memory is freed once arr goes out of scope, since
  // unique_ptr manages it.
}

int main() {
  unique_pointers();
  return 0;
}