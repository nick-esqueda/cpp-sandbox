//
// Created by Nick Esqueda on 8/21/25.
//

#include <iostream>

// Do not write code like this. You should use smart pointers instead of raw pointers and utilize RAII.
// This is for learning purposes only.

void array() {
  // size_t is the "proper" type to use for representing the size of anything
  const size_t arr_size = 10;

  // Can specify how much memory you want to allocate with `[x]`
  // The returned pointer points to the FIRST (0th) address in the block of memory allocated for you.
  int *arr_ptr = new int[arr_size];

  // Using `[2]` essentially means "go to the address `2 * sizeof(type)` over"
  arr_ptr[0] = 10;
  std::cout << *arr_ptr << std::endl; // Pointer points to the first address!!
  std::cout << arr_ptr[0] << std::endl; // Syntax sugar for the below pointer arithmetic
  std::cout << *(arr_ptr + 0) << std::endl; // Pointer arithmetic
  // All above are semantically the same!!

  arr_ptr[2] = 12;
  std::cout << arr_ptr[2] << std::endl;
  std::cout << *(arr_ptr + 2) << std::endl;

  for (int i = 0; i < arr_size; i++) {
    std::cout << "Array at: " << i << ": " << arr_ptr[i] << std::endl;
    // Note: remember any 0's you see in output are undefined behavior due to default initialization
  }

  // Must use the [] syntax!!! If you allocated space for multiple values (an array), you must use `delete[]`
  delete[] arr_ptr;
}

void single_value() {
  // `new` will allocate memory on the heap.
  // The type determines how much gets allocated. int = 4 bytes
  int *int_ptr = new int; // returns a pointer

  // At this point, the memory is allocated, but we used `new int` so it got "default initialized".
  // For class types, this calls the default constructor.
  // For fundamental types (int/long/etc.), this means "no initialization" -> indeterminant value.
  // Above leads to undefined behavior.

  // int *int_ptr2 = new int(); // <- This will "value-initialize" the int (0 for fundamental types)

  std::cout << int_ptr << std::endl;
  std::cout << *int_ptr << std::endl; // Dereference the pointer to get the value

  *int_ptr = 3; // Dereference the pointer to change the value at that location

  std::cout << int_ptr << std::endl;
  std::cout << *int_ptr << std::endl;

  // You MUST free the heap memory you took, otherwise you'll have a memory leak.
  delete int_ptr;
}

int main() {
  // single_value();
  array();
  return 0;
}
