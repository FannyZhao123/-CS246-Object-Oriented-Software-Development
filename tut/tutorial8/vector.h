#ifndef ___VECTOR__H_
#define ___VECTOR__H_

#include <iostream>

struct Vector{
   int size;
   int * fields;
   
   //Constructor(s)
   explicit Vector(int size);
   
   #ifdef BIGTHREE
   //Copy Constructor
   Vector(const Vector & v);
   //Destructor
   ~Vector();
   //Assignemnt Operator
   Vector& operator=(Vector v);
   #endif

   Vector operator+(const Vector & v);
   Vector operator-(const Vector & v);
   Vector operator*(const int & n);
   Vector operator/(const int & n);
};

std::ostream& operator<<(std::ostream &out, const Vector & v);

#endif
