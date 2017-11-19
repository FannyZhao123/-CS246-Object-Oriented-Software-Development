#include <iostream>
using namespace std;

//Hard to detect without valgrind
//This is also an interesting program,
//in that it will crash iff it is
//NOT run through valgrind (why?)
int main() {
  int *elements = new int[5];
  elements[5] = 5;
  cout << "elements[5] = " << elements[5] << endl;
  elements[-1] = 11;
  cout << "elements[-1] = " << elements[-1] << endl;
  delete [] elements;
  return 0;
}
