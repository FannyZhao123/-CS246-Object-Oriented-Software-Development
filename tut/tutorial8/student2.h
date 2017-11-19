#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <string>
#include <iostream>

struct Student{
  const unsigned int idNo;
  std::string name;
  double* grades;
  int numGrades;
  Student(unsigned int id, std::string n, double* gs, int ng);
  //Student(const Student& os);
};

std::ostream& operator<<(std::ostream& out, const Student& s);
#endif
