#include <iostream>
#include <string>

using namespace std;

class Animal{
  public:
    void Noise(){
      cout << "Animal Noise" << endl;
    }
    virtual void virtualNoise(){
      cout << "Generic Animal Noise" << endl;
    }
};

class Dog: public Animal{
  public:
    void Noise(){
      cout << "Woof" << endl;
    }
};

class Cat: public Animal{
  public:
    virtual void virtualNoise(){
      cout << "Purr" << endl;
    }
};

class Lion: public Cat{
  public:
    void Noise(){
      cout << "ROAR" << endl;
    }
};

class Fish: public Animal{};

class Whale: public Fish{
  public:
    virtual void virtualNoise(){
      cout << "WWWWWWWAAAAAALLLLLLLLLLLOOOOOOOOOOOOO" << endl;
    }
};

class Shark: public Fish{
  public:
    virtual void virtualNoise(){
      cout << "DaaaaaaaaaaaNum" << endl;
      cout << "DaaaaaaaaaaaNum" << endl;
      cout << "DaaaaNum" << endl;
      cout << "DaaaaNum" << endl;
      cout << "DaNum DaNum" << endl;
    }
};

int main(){
  Animal A;
  cout << "Animal" << endl;
  A.Noise();				// calls Animal Noise()
  A.virtualNoise();    // calls Animal virtualNoise()
  cout << endl << "Dog" << endl;
  Dog D;
  D.Noise();				// calls Dog Noise()
  D.virtualNoise();		// calls Dog virtualNoise()

  cout << endl << "Cat" << endl;
  Cat C;
  C.Noise();				// calls Cat Noise()
  C.virtualNoise();		// calls Cat virtualNoise()

  cout << endl << "Lion" << endl;
  Lion L;
  L.Noise();				// calls Lion Noise()
  L.virtualNoise();		// calls Lion virtualNoise()

  cout << endl << "Fish" << endl;
  Fish F;
  F.Noise();				// calls Fish Noise()
  F.virtualNoise();		// calls Fish virtualNoise()

  cout << endl << "Whale" << endl;
  Whale W;
  W.Noise();				// calls Whale Noise()
  W.virtualNoise();		// calls Whale virtualNoise()

  cout << endl << "Shark" << endl;
  Shark S;
  S.Noise();				// calls Shark Noise()
  S.virtualNoise();		// calls Shark virtualNoise()


  // Fill in which noises are which
  Animal * pA = &D;

  cout << endl << "Animal Pointer to Dog" << endl;
  pA->Noise();			// calls Animal Noise()
  pA->virtualNoise();

  cout << endl << "Animal Pointer to Cat" << endl;
  pA = &C;
  pA->Noise();
  pA->virtualNoise();

  cout << endl << "Animal Pointer to Lion" << endl;
  pA = &L;
  pA->Noise();
  pA->virtualNoise();

  cout << endl << "Animal Pointer to Fish" << endl;
  pA = &F;
  pA->Noise();
  pA->virtualNoise();

  cout << endl << "Animal Pointer to Whale" << endl;
  pA = &W;
  pA->Noise();
  pA->virtualNoise();

  cout << endl << "Animal Pointer to Shark" << endl;
  pA = &S;
  pA->Noise();
  pA->virtualNoise();
}
