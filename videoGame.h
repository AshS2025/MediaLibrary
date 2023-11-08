#include <iostream>
#include "Parent.h"

using namespace std;

class videoGame : public Parent {
 public:
  videoGame(char*, int, int, char*);
  char* getPublisher();
  int getRating();
 protected:
  char* publisher;
  int rating;
  char* title;
  int year = 1;


};
