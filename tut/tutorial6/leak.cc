#include <iostream>
using namespace std;

int **glob_possible;
int **glob_reachable;
int main() {
  cout << "Leaking 40 bytes definitely..." << endl;
  int ***ptrs = new int**[5];
  cout << "16 bytes indirectly..." << endl;
  *ptrs = new int*[2];
  cout << "24 bytes possibly..." << endl;
  glob_possible = new int*[3];
  glob_possible++;
  cout << "And 56 bytes still reachable..." << endl;
  glob_reachable = new int*[7];
  return 0;
}
