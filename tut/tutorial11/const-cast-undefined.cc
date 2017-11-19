#include <iostream>

int main() {
  const int i = 5;
  int *j = const_cast<int*>(&i);
  *j = 3;
  std::cout << "The value of i is " << i
            << " and the value of j is " << *j << std::endl;
  return 0;
}
