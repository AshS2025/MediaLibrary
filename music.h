#include <iostream>
#include "Parent.h"

using namespace std;

//child of parent
class music : public Parent {
 public:
  music(char*, int, char*, float, char*);
  ~music();
  //already has getTitle and getYear from parent
  char* getArtist();
  float getDuration();
  char* getPublisher();
  void printStuff(); //overrides virtual printStuff in parent
private: //all variables specific to music type
  char* publisher;
  float duration;
  char* artist;
  char* title;
  int year = 3;
};
