#include "multitree.h"

MultiTree::MultiTree(int size):data(0),size(size),children(new MultiTree*[size]) {
  for (int i=0;i<size;i++) {
    children[i] = 0;
  }
}
MultiTree::MultiTree(int size,int data):data(data),size(size),
                                        children(new MultiTree*[size]) {
  for (int i=0;i<size;i++) {
    children[i] = 0;
  }
}

MultiTree::~MultiTree() {
  for (int i=0;i<size;i++) {
    delete children[i];
  }
  delete [] children;
}

MultiTree::MultiTree(const MultiTree &other):data(other.data),size(other.size),
                                             children(new MultiTree*[size]) {
  for (int i=0;i<size;i++) {
    children[i] = other.children[i] ? new MultiTree(*other.children[i]) : 0;
  }
}

void MultiTree::setChild(int index,MultiTree *value) {
  children[index] = value;
}

MultiTree *MultiTree::getChild(int index) {
  return children[index];
}

int MultiTree::getData() const {
  return data;
}

void MultiTree::swap(MultiTree &other) {
  int tmpdata = other.data;
  int tmpsize = other.size;
  MultiTree **tmpchildren = other.children;

  other.data = data;
  data = tmpdata;

  other.size = size;
  size = tmpsize;

  other.children = children;
  children = tmpchildren;
}

#ifndef COPYSWAP
MultiTree &MultiTree::operator=(const MultiTree &other) {
  if (this==&other) return *this;
  for (int i=0;i<size;i++) {
    delete children[i];
  }
  delete [] children;
  data = other.data;
  size = other.size;
  children = new MultiTree*[size];
  for (int i=0;i<size;i++) {
    children[i] = other.children[i] ? new MultiTree(*other.children[i]) : 0;
  }
  return *this;
}
#else
MultiTree &MultiTree::operator=(const MultiTree &other) {
  MultiTree tmp = other;
  swap(tmp);
  return *this;
}
#endif
