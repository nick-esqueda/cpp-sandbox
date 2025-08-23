//
// Created by Nick Esqueda on 8/22/25.
//

#include "Point.h"

#include <iostream>

Point::Point(const int x, const int y) : x(x), y(y) {}

// Operator overloading = tells the compiler what to do when operators are using
// with your class.
// The parameter takes in the object on the right hand side (rhs) of the
// operator at the call site.
Point Point::operator+(const Point &rhs) const {
  // "Braced initializer list" - (clang-tidy suggestion)
  // Prevents having "Point" in both the return type and the return statement
  // (non-functional)
  return {x + rhs.x, y + rhs.y};
  // return Point(x + rhs.x, y + rhs.y);
}

// Return a reference to `this` Point.
Point &Point::operator+=(const Point &rhs) {
  x = x + rhs.x;
  y = y + rhs.y;
  // `this` is a POINTER to the current class instance. must dereference the
  // pointer to get the actual value.
  return *this;
}

void Point::print() const {
  std::cout << "Point(x=" << x << ", y=" << y << ")" << std::endl;
}