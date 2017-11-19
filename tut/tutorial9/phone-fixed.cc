#include <iostream>
using namespace std;

class Computer{
  public:
    virtual void makeCall(){ cout << "Making call through the power of the internet\n";}
    void test(){cout << "Dialing out\n";}
};
class Smartphone : public Computer {
  public:
    virtual void makeCall(){ cout << "Attempting to make a call through Rogers\n";}
};
void testCall(Computer& c){
  c.test();
  c.makeCall();
}
int main(){
  Smartphone Nexus4;
  testCall(Nexus4);
  Computer * phone = new Smartphone;
  phone->makeCall();
  Nexus4.makeCall();
  Nexus4.test();
}
