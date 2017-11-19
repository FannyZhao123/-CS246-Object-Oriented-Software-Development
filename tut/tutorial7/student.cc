#include <string>
#include <iostream>
#include "student.h"

using namespace std;

Student::Student(unsigned int id, string n, double g){
  idNo = id;
  name = n;
  grade = g;
}

int main(){
  Student bob(2039273, "Bobby Bob", 75);
  cout << bob.name << ", " << bob.idNo << ": " << bob.grade << "%" << endl;
  return 0;
}
