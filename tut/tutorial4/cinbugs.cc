#include <iostream>
using namespace std;

int main() {
  int i;
  //Try to interpret the start of the stream as a number
  if (cin >> i) {
    cout << "Found number " << i << endl;
  //Try to interpret the start of the stream as a string
  } else {
    cin.clear();
    string s;
    cin >> s;
    cout << "Found string " << s << endl;
  }
}
