#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <string>

struct Student{
  unsigned int idNo;
  std::string name;
  double grade;
  Student(unsigned int id, std::string n, double g);
};

#endif
