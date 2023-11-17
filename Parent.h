#ifndef PARENT_H //header guard!
#define PARENT_H
#include <iostream>
#include <cstring>

using namespace std;

class Parent { //all children can use these things!
public: 
  Parent(int, char*); //constructor
  virtual ~Parent(); //virtual destructor
  char* getTitle();
  int getYear();
  virtual void printStuff(); //virtual print method
 protected:
  char* title;
  int year = 0;
  
};

#endif
