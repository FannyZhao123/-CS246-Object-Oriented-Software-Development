#ifndef LINKED_H
#define LINKED_H
#include "node.h"
#include <vector>

class LinkedList {
  Node *first;
  Node *last;

  void computeLast();
  public:
    LinkedList(std::vector<int>&);
    ~LinkedList();

    void remove(std::vector<int>&);
};

#endif
