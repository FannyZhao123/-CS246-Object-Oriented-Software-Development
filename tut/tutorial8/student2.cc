#include "student2.h"
#include <string>
#include <iostream>

using namespace std;

Student::Student(unsigned int id, string n, double gs[], int ng):idNo(id),
                name(n), grades(new double[ng]), numGrades(ng){
  for (int i = 0; i < numGrades; ++i){
    grades[i] = gs[i];
  }
}

ostream& operator<<(ostream& out, const Student& s){
  out << s.name << ", " << s.idNo << ":";
  for (int i = 0; i < s.numGrades; ++i){
    out << " " << s.grades[i];
  }
  return out;
}

/*
Student::Student(const Student& os):idNo(os.idNo+2000),
	name(os.name+" Clone"), grades(new double[os.numGrades]), numGrades(os.numGrades){
    for (int i = 0; i < grades; ++i)
      grades[i] = os.grades[i];
}
*/


int main(){
  double* grades = new double[3];
  grades[0] = 75.6;
  grades[1] = 82.3;
  grades[2] = 78.2;
  Student bob(808,"Bob",grades,3);
  cout << bob << endl;
  Student billy = bob;
  billy.name = "Billy";
  billy.grades[0] = 100;
  cout << billy << endl;
  cout << bob << end;
  return 0;
}
