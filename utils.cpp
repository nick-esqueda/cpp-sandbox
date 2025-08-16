//
// Created by Nick Esqueda on 8/12/25.
//

#include "utils.h"
#include <iostream>

void func() {
  std::cout << "printing from func()\n";
}

int add(const int a, const int b) {
  return a + b;
}

void printNum(const int num) {
  std::cout << num << std::endl;
}
