#include <iostream>
using namespace std;

struct myIntStruct {
  int val;
};

int main() {
  myIntStruct *s = new myIntStruct;
  cout << "Deleting s after setting s->val to 42..." << endl;
  s->val = 42;
  delete s;
  cout << "The value of s->val is " << s->val << endl;
  cout << "Setting s->val to 42 again..." << endl;
  s->val = 42;
  cout << "The value of s->val is " << s->val << endl;
  return 0;
}
