#include <iostream>
#include <map>

void arrayDemo() {
  int integerArray[5] = {10, 20, 30, 40, 50};

  for (const int &num: integerArray) {
    std::cout << "int from array: " << num << std::endl;
  }
}

void listDemo() {
  std::vector<int> integerList = {5, 4, 3, 2, 1};
  std::cout << integerList.at(3) << std::endl;

  for (const int &num: integerList) {
    std::cout << "int from list: " << num << std::endl;
  }
}

void stringDemo() {
  const std::string str = "hello";
  for (const char c: str) {
    std::cout << c << std::endl;
  }
}

void mapDemo() {
  // std::map is an ordered map, implemented as a self-balancing BST (Red-Black Tree)
  // use it only when keys need to be sorted
  // by default, maps are ordered by keys (ascending)
  std::map<int, std::string> orderedMap;
  orderedMap[3] = "three";
  orderedMap[2] = "two";
  orderedMap[1] = "one";

  std::cout << "ORDERED MAP:\n";
  for (const std::pair<int, std::string> pair : orderedMap) {
    std::cout << pair.first << ": " << pair.second << "\n";
  }

  // std::unordered_map is a hash table - essentially equivalent to Java's HashMap<>()
  // sorting order of the pairs during iteration is not guaranteed
  std::unordered_map<int, std::string> hashMap;
  hashMap[1] = "one";
  hashMap[2] = "two";
  hashMap[3] = "three";

  std::cout << "UNORDERED MAP:\n";
  for (const std::pair<int, std::string> pair : hashMap) {
    std::cout << pair.first << ": " << pair.second << "\n";
  }
}

int main() {
  stringDemo();
  arrayDemo();
  listDemo();
  mapDemo();
  return 0;
}
