#include <iostream>
using namespace std;

int main() {
  int *i = new int[5];
  cout << "Deleting i..." << endl;
  delete [] i;
  cout << "Deleting i again..." << endl;
  delete [] i;
  cout << "Done" << endl;
  return 0;
}
