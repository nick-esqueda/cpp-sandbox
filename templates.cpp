//
// Created by Nick Esqueda on 8/26/25.
//

#include <iostream>
#include <vector>

// One "generic" function that handles multiple types
template <typename T> void template_print_each(const std::vector<T> &list) {
  for (const T &i : list) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

void duplicated_print_each(const std::vector<int> &int_list) {
  for (const int &i : int_list) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

void duplicated_print_each(const std::vector<float> &float_list) {
  for (const float &i : float_list) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

void templates() {
  const std::vector int_list = {1, 2, 3};
  const std::vector float_list = {1.1f, 2.2f, 3.3f};
  duplicated_print_each(int_list);
  duplicated_print_each(float_list);

  template_print_each(int_list);
  template_print_each(float_list);
}

int main() {
  templates();
  return 0;
}