#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int generate_int(){
  return (rand() % 20) + 1;
}
int main(){
  srand(time(0));
  vector<int> myVector(10000); // reserve space for 10,000 ints

  // Fill myVector with 10,000 random ints using the generate function from <algorithm>
  generate(myVector.begin(), myVector.end(), generate_int);
  /* Alternate:
  for(vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++){
    *it = generate_int();
  }
  */
  map<int,int> occurrences;
  // Count the number of occurrences of each randomly generated number
  // Use an associative container to keep track
  for(vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++){
    if(occurrences.count(*it) == 0) occurrences[*it] = 0; // Initialize container element if previously unseen
    occurrences[*it] += 1;
  }
  // Note: That the above check may not be necessary, assuming your compiler initializes POD to 0 
  // for STL containers

  // map stores data based upon sorted key order, so iteration will print from 1 to 10
  // map iterator returns a pair<P,Q> so we must get the first and second values individually
  for(map<int,int>::reverse_iterator it = occurrences.rbegin(); it != occurrences.rend(); it++){
    cout << it->first << ": "  << it->second << endl;
  }
}
