//
// Created by Nick Esqueda on 8/16/25.
//

#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
  if (b == 0) {
    throw std::runtime_error("Cannot divide by 0");
  }
  if (a == 2) {
    throw 33; // You can throw and catch ANYTHING, even an int (but please don't)
  }
  return a / b;
}

void exception_handling() {
  // Notes:
  // There are no "checked exceptions" in C++ - runtime only.
  // Most standard exceptions inherit from `std::exception`
  // When creating your own custom exception, inherit from `std::exception`
  // Technically, anything can be `throw`n, but best practice is to throw something inheriting `std::exception`.

  try {
    std::cout << divide(2, 0) << std::endl;
  } catch (const std::runtime_error& e) { // Catch exceptions by reference! (&)
    std::cerr << "Runtime exception occurred: " << e.what() << std::endl;
  } catch (const std::exception& e) {
    // Catch-all for any other type of `std::exception`
    std::cerr << "Other exception occurred: " << e.what() << std::endl;
  } catch (const int& e) {
    // You can throw and catch ANYTHING, even an int (but please don't)
    std::cerr << "Caught an int? -> " << e << std::endl;
  } catch (...) {
    // Catch-all for non-standard exceptions
    std::cerr << "Unknown exception caught" << std::endl;
  }
}

int main() {
  exception_handling();
  return 0;
}