//
// Created by Nick Esqueda on 7/31/25.
//

#include <iostream>

void func1(std::string str) {
  // This does NOT modify the string which was passed in.
  // "str" here holds a copy of the passed in value.
  str += "!";
  std::cout << str << "\t<- Modified value in callee\n";
}

void func2(std::string &str) {
  // Modifies the passed in value, since `&str` points to the original object in memory
  str += "!";
  std::cout << str << "\t<- Modified value in callee\n";
}

void func3(const std::string &str) {
  // You can pass in a reference to the original object while also forcing it to be `const`, so it can't be modified
  // This saves memory while also preventing the original value from being modified
  // str += "!"; // Compile error
}

void passByValue() {
  std::cout << "### PASS BY VALUE ###\n";
  std::string str = "test"; // Could be made `const` since func1 won't modify this value
  std::cout << str << "\t<- Original value in caller\n";
  func1(str); // string value is COPIED into the function
  std::cout << str << "\t<- Original value in caller\n";
}

void passByReference() {
  std::cout << "### PASS BY REFERENCE ###\n";
  std::string str = "test";
  std::cout << str << "\t<- Original value in caller\n";
  func2(str); // string value REFERENCE is passed into the function
  std::cout << str << "\t<- Modified value in caller\n";
}

void passByReferenceConst() {
  std::string str = "test";
  func3(str);
}

int main() {
  passByValue();
  passByReference();
  passByReferenceConst();
  return 0;
}
