#ifndef PARENT_H
#define PARENT_H
#include <iostream>
#include <cstring>

using namespace std;

class Parent {
 public:
  Parent(int, char*);
  char* getTitle();
  int getYear();
 protected:
  char* title;
  int year = 0;
  
};

#endif
