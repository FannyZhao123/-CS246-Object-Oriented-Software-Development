#include "node.h"

Node::Node(int data):data(data),next(0) {}
Node::Node(int data,Node *next):data(data),next(next) {}
Node::~Node() { delete next; }
int Node::getData() const { return data; }
Node *Node::getNext() { return next; }
void Node::setNext(Node *next) { this->next = next; }
