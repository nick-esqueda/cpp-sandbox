//
// Created by Nick Esqueda on 8/16/25.
//

#ifndef CLASSES_H
#define CLASSES_H
#include <string>

// class member variables and method signatures should be declared in a header
// file. define them in the source files.
class Thing {
  // members variables should be prefixed with "m_" by convention
  int m_num;
  bool m_is_bool;

  // fields/methods are private by default. use `public:` to specify public
  // methods/fields
public:
  Thing();

  Thing(int m_num, bool m_is_bool);

  void set_num(int num);

  void set_is_bool(bool boolean);

  [[nodiscard]] std::string to_string() const;
};

#endif // CLASSES_H
