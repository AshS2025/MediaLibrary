#include <iostream>
#include "Parent.h"

using namespace std;

//child of parent
class movie : public Parent { //initializations of functions and variables
 public:
  movie(char*, int, char*, int, float);
  ~movie();
  char* getDirector();
  int getRating();
  float getDuration();
  void printStuff();
 private:
  char* director;
  int rating;
  char* title;
  int year = 2;
  float duration;
};
