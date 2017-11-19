#ifndef NODE_H
#define NODE_H

class Node {
  const int data;
  Node *next;
  public:
    Node(int);
    Node(int,Node*);
    ~Node();
    int getData() const;
    Node *getNext();
    void setNext(Node *node);
};

#endif
