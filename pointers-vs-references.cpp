//
// Created by Nick Esqueda on 8/1/25.
//

#include <iostream>

void references() {
  std::cout << "\n### REFERENCES ###\n";

  // References provide another way to reference an existing value in memory
  // Like an "alias" for a value
  int x = 0;
  int &x_ref = x;
  std::cout << x << "\t<- x\n";
  std::cout << x_ref << "\t<- x_ref\n";

  // Modifications will be reflected in both variables, since they both update the same value in memory
  x++;
  x_ref++;
  std::cout << x << "\t<- x\n";
  std::cout << x_ref << "\t<- x_ref\n";

  // References CANNOT be reassigned like pointers can
  int i = 1;
  int j = 2;
  int &ref = i;
  // &ref = j; // compile error

  // Another example...
  int y = 10;
  x_ref = y; // this updates the value in &x to be 10! it doesn't point x_ref to y
  std::cout << x_ref << "\t<- x_ref\n";

  // References CANNOT be NULL - they must be tied to an existing variable
  // int &bad_ref; // compile error
  int *good_ptr; // note how you can declare a pointer without initializing (will hold garbage memory address)

  // Can't do arithmetic with references like pointer arithmetic
  // int &x_ref2 = &x + 1; // compile error

  // References help clean up the slightly messy syntax of managing pointers when needing to use reference types
}

void pointers() {
  std::cout << "\n### POINTERS ###\n";

  // Pointers hold the MEMORY ADDRESS for another value
  int x = 5;
  int y = 8;
  int *x_ptr; // note how you can declare a pointer without initializing (will hold garbage memory address)
  x_ptr = &x;
  int *y_ptr = &y;
  std::cout << x_ptr << "\t<- x_ptr\n";
  std::cout << y_ptr << "\t<- y_ptr\n";

  // Pointers can be reassigned to another memory address.
  std::cout << "swapping pointer values...\n";
  x_ptr = &y;
  y_ptr = &x;
  std::cout << x_ptr << "\t<- x_ptr after swap\n";
  std::cout << y_ptr << "\t<- y_ptr after swap\n";
}

int main() {
  pointers();
  references();
  return 0;
}
