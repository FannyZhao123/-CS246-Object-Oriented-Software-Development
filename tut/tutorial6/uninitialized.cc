#include <iostream>
using namespace std;

struct myIntStruct {
  int val;
};

int main() {
  int i;
  int j = i + 1;
  cout << "The value of j is " << j << endl;
  myIntStruct *s = new myIntStruct;
  cout << "The value of s->val is " << s->val << endl;
  delete s;
  return 0;
}
