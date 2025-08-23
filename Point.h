//
// Created by Nick Esqueda on 8/22/25.
//

#ifndef POINT_H
#define POINT_H

class Point {
  int x;
  int y;

public:
  Point(int x, int y);

  // Operator overloading - see implementation for notes
  Point operator+(const Point &rhs) const;

  Point &operator+=(const Point &rhs);

  void print() const;
};

#endif // POINT_H
