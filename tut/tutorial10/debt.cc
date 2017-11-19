#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <utility>
#include <limits>

typedef std::map<std::string,int> debtMap_t;
typedef std::pair<std::string,int> person_t;

void readInput(debtMap_t &debtMap) {
  std::string name;
  int debt;
  std::string otherName;
  while (std::cin >> name >> debt >> otherName) {
    debtMap[name] += debt;
    debtMap[otherName] -= debt;
  }
}

const person_t &maxPerson(const person_t &p1, const person_t &p2) {
  return p1.second > p2.second ? p1 : p2;
}

void printMaxDebt(debtMap_t &debtMap) {
  person_t max("Average Joe",std::numeric_limits<int>().min());
  max = std::accumulate(debtMap.begin(),debtMap.end(),max,maxPerson);
  std::cout << max.first << " owes the most, clocking in at $"
            << max.second << std::endl;
}

int main() {
  debtMap_t debtMap;
  readInput(debtMap);
  printMaxDebt(debtMap);
  return 0;
}
