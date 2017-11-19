#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <iterator>
using namespace std;

void print_pair(pair<int,int> p){
  cout << p.first << ": " << p.second << endl;
}

class Occurrences{
  map<int,int> occurrences;
public:
  void operator() (int i){
    if(occurrences.count(i) == 0) occurrences[i] = 1;
    occurrences[i]+=1;
  }
  void print(){
    for_each(occurrences.begin(),occurrences.end(), print_pair);
  }
};

int main(){
  // Generating ints is lame, I want stuff from the user
  istream_iterator<int> eos; // end of stream iterator
  istream_iterator<int> cin_iterator(cin); // need to specify type, so we know what to pull from cin

  // Copy input from cin to the vector
  // We can copy from one source to another using iterators
  vector<int> myVector(cin_iterator, eos);

   /* Use a function object and for_each to simplify counting and printing
  Notes:
    - for_each copies the function object passed in
    - This means to accumlate state in the function object, for_each returns the copy for assignment
    - Could be more efficient by shallow copying the map using a pointer - removes the need for assignment
  */
  Occurrences occurrences = for_each(myVector.rbegin(), myVector.rend(), Occurrences());
  occurrences.print();
}
