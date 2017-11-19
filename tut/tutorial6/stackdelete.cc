#include <iostream>
using namespace std;

void del(int *ptr) {
  delete [] ptr;
  cout << "Deleted pointer" << endl;
}

int main() {
  int *ptr = new int[5];
  cout << "Deleting heap pointer..." << endl;
  del(ptr);
  int ptr2[5];
  cout << "Deleting stack pointer..." << endl;
  del(ptr2);
  return 0;
}
