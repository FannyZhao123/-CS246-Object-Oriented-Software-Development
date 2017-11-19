#include <iostream>
#include <string>
using namespace std;

struct Rational{
  int numer, denom;
  double toDouble(){
    return (double) numer/denom;
  }

};
Rational operator+(const Rational& lhs, const Rational &rhs){
  Rational temp;
  temp.numer = lhs.numer * rhs.denom + lhs.denom * rhs.numer;
  temp.denom = lhs.denom * rhs.denom;
  return temp;
}
ostream& operator<<(ostream& out, const Rational &r){
  out << r.numer << "/" << r.denom;
}
