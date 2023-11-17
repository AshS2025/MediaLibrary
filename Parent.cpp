#include <iostream>
#include <cstring>
#include "Parent.h"

using namespace std;

//constructor
//this is p much never used in the actual program because the function just calls the object specific constructor
Parent::Parent(int year, char* title) {
  this->year = year;
  this->title = new char[90];
  strcpy(this->title, title);
  
}

//returns year of media
//used by children
int Parent::getYear(){
  return year;
}

//returns title
//used by children
char* Parent:: getTitle(){
  return title;
}

//definition of printStuff function
//is pretty much always overridden by child's printStuff function
void Parent:: printStuff(){
  cout << this->getTitle();
  cout << this->getYear();
}

//virtual destructor definition
//again p much always overriden
Parent:: ~Parent(){
  delete title;
}
