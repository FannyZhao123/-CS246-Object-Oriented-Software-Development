#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <iterator>
using namespace std;

void print_pair(pair<int,int> p){
  cout << p.first << ": " << p.second << endl;
}

int main(){
  // Generating ints is lame, I want stuff from the user
  istream_iterator<int> eos; // end of stream iterator
  istream_iterator<int> cin_iterator(cin); // need to specify type, so we know what to pull from cin

  // Copy input from cin to the vector
  // We can copy from one source to another using iterators
  vector<int> myVector(cin_iterator, eos);

  map<int,int> occurrences;
  // Count the number of occurrences of each randomly generated number
  // Use an associative container to keep track
  for(vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++){
    if(occurrences.count(*it) == 0) occurrences[*it] = 1; // Initialize container element if previously unseen
    occurrences[*it] += 1;
  }
  // Note: That the above check may not be necessary, assuming your compiler initializes POD
  // to 0 for STL containers

  // Use for_each to iterate over element in the occurrences map
  for_each(occurrences.rbegin(),occurrences.rend(), print_pair);
}
