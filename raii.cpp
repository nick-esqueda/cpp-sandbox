//
// Created by Nick Esqueda on 8/22/25.
//

#include <iostream>

/**
 * RAII = Resource Acquisition Is Initialization
 *
 * WHAT?
 * Programming technique that ties the acquisition and freeing of resources
 * (memory, file handles, etc.) to object lifetimes.
 *
 * WHY?
 * It delegates the responsibility of freeing memory to the compiler instead of
 * the user. This gets rid of the need to manually manage memory and other
 * resources, which causes of a lot of bugs historically.
 *
 * HOW?
 * Wrap the resource in an object whose constructor/destructor handles
 * acquisition/release. Destructors run when objects go out of scope, so the
 * resource will naturally be freed. RAII works by tying heap memory back to
 * scope.
 *
 * WHEN?
 * It is always a good idea to practice RAII or utilize tools implementing RAII.
 */

// EXAMPLE ONLY - in practice, you should use smart pointers for this situation.
class RaiiArray {
public:
  int *data;

  RaiiArray(const size_t size) {
    // Allocate memory here in the constructor
    data = new int[size];
  }

  ~RaiiArray() {
    // Free memory to prevent memory leaks!
    // This destructor will always run when the object goes out of scope.
    delete[] data;
  }
};

void good() {
  RaiiArray arr(10);
  arr.data[0] = 10;

  std::cout << arr.data[0] << std::endl;

  // Good! No need to `delete[]` the array - the destructor handles it for us.
}

void bad() {
  int *arr = new int[10];
  arr[0] = 10;

  std::cout << arr << std::endl;
  std::cout << arr[0] << std::endl;

  // MEMORY LEAK! Forgot to `delete[] arr;`!
  // Using RAII can
}

int main() {
  // bad();
  good();
  return 0;
}