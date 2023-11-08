#include <iostream>
#include <cstring>
#include "Parent.h"

using namespace std;

Parent::Parent(int year, char* title) {
  this->year = year;
  this->title = new char[90];
  strcpy(this->title, title);
  
}

int Parent::getYear(){
  return year;
}

char* Parent:: getTitle(){
  return title;
}
