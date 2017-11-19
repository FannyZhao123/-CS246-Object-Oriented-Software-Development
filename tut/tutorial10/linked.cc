#include "linked.h"

LinkedList::LinkedList(std::vector<int> &elements):first(0) {
  Node *curr = 0;
  for (std::vector<int>::const_iterator it=elements.begin();
       it != elements.end();
       ++it) {
    Node *newn = new Node(*it);
    if (!curr) {
      first = newn;
    } else {
      curr->setNext(newn);
    }
    curr = newn;
  }
  computeLast();
}

LinkedList::~LinkedList() {
  delete first;

  delete last;
}

void LinkedList::computeLast() {
  if (!first) {
    last = 0;
  } else {
    Node *curr = first;
    while (curr->getNext()) {
      curr = curr->getNext();
    }
    last = curr;
  }
}

void LinkedList::remove(std::vector<int> &elements) {
  for (std::vector<int>::const_iterator it = elements.begin();
       it != elements.end();
       ++it) {
    if (!first) {
      break;
    } else if (first->getData() == *it) {
      Node *tmp = first->getNext();
      delete first;
      first = tmp;
    } else {
      Node *curr = first;
      Node *prev = 0;
      do {
        if (curr->getData() == *it) {
          prev->setNext(curr->getNext());
          delete curr;
          break;
        }
        prev = curr;
        curr = curr->getNext();
      } while (curr);
    }
  }
  computeLast();
}
