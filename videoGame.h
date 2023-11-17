#include <iostream>
#include "Parent.h"

using namespace std;

//child of Parent
class videoGame : public Parent { //iniializations of functions and variables
 public:
  videoGame(char*, int, int, char*);
  ~videoGame();
  char* getPublisher();
  int getRating();
  void printStuff();
 private:
  char* publisher;
  int rating;
  char* title;
  int year;

};
