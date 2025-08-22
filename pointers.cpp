//
// Created by Nick Esqueda on 7/31/25.
//

#include <iostream>

void pointer_operators() {
  std::cout << "\n### OPERATORS ###\n";

  int x = 1;
  std::cout << x << "\t\t\t<- x\n";

  // The "&" operator "gets the address" of the variable
  // Useful mnemonic = "&"/"Ampersand"/"Address" -> "Give me the &Address of this variable"
  int *x_ptr = &x;
  std::cout << x_ptr << "\t<- pointer to x\n";

  // The "*" operator will "dereference" the pointer, meaning it retrieves the value in the pointer's address
  int x_val = *x_ptr;
  std::cout << x_val << "\t\t\t<- x value retrieved from pointer\n";
}

void pointer_value_vs_reference() {
  std::cout << "\n### VALUES VS. REFERENCE ###\n";
  int x = 5;
  int y = x; // passed by value, so y's value is independent of x

  std::cout << x << "\t\t\t<- x\n";
  std::cout << y << "\t\t\t<- y\n";

  x = 7;
  std::cout << "reassigning x = 7...\n";
  std::cout << x << "\t\t\t<- x\n";
  std::cout << y << "\t\t\t<- y\n";

  int *x_ptr = &x; // it's just the value of the address
  int *x_ptr2 = x_ptr; // ... and gets copied into this new variable
  std::cout << x_ptr << "\t<- x pointer\n";
  std::cout << x_ptr2 << "\t<- x pointer 2\n";

  // dereference and copy the x value into another var
  int z = *x_ptr;
  std::cout << z << "\t\t\t<- z (x)\n";

  *x_ptr = 10;
  std::cout << x << "\t\t\t<- x (new after ptr update)\n";
  std::cout << z << "\t\t\t<- z (x)\n";
  std::cout << *x_ptr2 << "\t\t\t<- x_ptr2\n";

}

int main() {
  pointer_operators();
  pointer_value_vs_reference();
  return 0;
}
