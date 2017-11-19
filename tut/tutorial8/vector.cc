#include <iostream>
#include <string>
#include <sstream>
#include "Vector.h"

using namespace std;

#ifdef BIGTHREE

//Copy Constructor
Vector::Vector(const Vector & v):size(v.size),fields(new int[size]){
   for (int i = 0; i < size ; ++i){
      fields[i] = v.fields[i];
   }
}
//Destructor
Vector::~Vector(){
   delete[] fields;
}
#ifdef COPYSWAP
//Assignemnt Operator
//Using copy and swap idiom
Vector& Vector::operator=(Vector v){
   int temp_size = v.size;
   v.size = this->size;
   this->size = temp_size;

   int * temp_fields = v.fields;
   v.fields = this->fields;
   this->fields = temp_fields;

   return *this;
}
#else
// A good operator=
// Deletion happens after successful allocation
// this is left in valid state if new fails
Vector& Vector::operator=(const Vector& v){
   if(this == &v) return *this;
   int* temp_fields = new int[v.size];
   for (int i=0;i<v.size;i++) {
     temp_fields[i] = v.fields[i];
   }
   size = v.size;
   delete fields;
   fields = temp_fields;
   return *this;
}
#endif
#endif

Vector::Vector(int size):size(size), fields(size > 0 ? new int[size] : NULL){
   for (int i = 0; i < size; ++i)
      fields[i] = 0;
}



ostream& operator<<(ostream &out, const Vector & v){
   out << "(" << v.fields[0];
   for (int i = 1; i < v.size; ++i){
      out << "," << v.fields[i];
   }
   out << ")";
   return out;
}

Vector Vector::operator+(const Vector & v){
   if (size != v.size){
      cout << "Cannot add vectors of different sizes. Empty returned." << endl;
      Vector empty(size);
      return empty;
   }
   Vector temp(size);
   for (int i = 0; i < size; ++i){
      temp.fields[i] = fields[i] + v.fields[i];
   }
   return temp;
}

Vector Vector::operator-(const Vector & v){
   if (size != v.size){
      cout << "Cannot subtract vectors of different sizes. Empty returned." << endl;
      Vector empty(size);
      return empty;
   }
   Vector temp(size);
   for (int i = 0; i < size; ++i){
      temp.fields[i] = fields[i] - v.fields[i];
   }
   return temp;
}

Vector Vector::operator*(const int & n){
   Vector temp(size);
   for (int i = 0; i < size; ++i){
      temp.fields[i] = fields[i]*n;
   }
   return temp;
}

Vector Vector::operator/(const int & n){
   Vector temp(size);
   for (int i = 0; i < size; ++i){
      temp.fields[i] = fields[i]/n;
   }
   return temp;
}

