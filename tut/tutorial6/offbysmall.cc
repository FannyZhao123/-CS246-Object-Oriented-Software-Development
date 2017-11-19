#include <iostream>
using namespace std;

//This is an example of an error valgrind can't (!) catch
void set(int *arr,int ind,int val) {
  arr[ind] = val;
}

int main() {
  int i=5;
  int elements[5];
  int j=7;
  cout << "i = " << i << endl;
  cout << "j = " << j << endl;
  //These offsets were chosen to work correctly on the student environment
  //using g++. They may work differently on a different system and compiler.
  //They should be (&v - elements)/4 for v in {i,j}
  cout << "Assigning to elements[6]..." << endl;
  set(elements,6,2);
  cout << "i = " << i << endl;
  cout << "j = " << j << endl;
  cout << "Assigning to elements[7]..." << endl;
  set(elements,7,9);
  cout << "i = " << i << endl;
  cout << "j = " << j << endl;
  return 0;
}
