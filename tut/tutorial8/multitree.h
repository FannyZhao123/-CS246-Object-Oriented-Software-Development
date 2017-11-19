#ifndef MULTI_TREE_H
#define MULTI_TREE_H

class MultiTree {
  int data;
  int size;
  MultiTree **children;

  public:
    explicit MultiTree(int size);
    MultiTree(int size,int data);
    MultiTree(const MultiTree&);
    MultiTree &operator=(const MultiTree&);
    ~MultiTree();
    void setChild(int index,MultiTree *value);
    MultiTree *getChild(int index);
    int getData() const;
    void swap(MultiTree &);
};

#endif
