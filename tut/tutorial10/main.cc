#include "linked.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;
  vec.push_back(2);
  vec.push_back(5);
  vec.push_back(3);
  vec.push_back(1);
  vec.push_back(7);

  std::cout << "Making a new ll with five elements" << std::endl;
  LinkedList *ll = new LinkedList(vec);

  std::vector<int> vec2;
  vec2.push_back(3);
  vec2.push_back(7);

  std::cout << "Removing 3 and 7 from the ll" << std::endl;
  ll->remove(vec2);

  std::cout << "Deleting ll" << std::endl;
  delete ll;

  std::cout << "Returning" << std::endl;
  return 0;
}
