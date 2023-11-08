#include <iostream>
#include <cstring>
#include "Parent.h"
#include "videoGame.h"

using namespace std;

videoGame::videoGame(char* title, int year, int rating, char* publisher): Parent(year, title){
  this->publisher = new char[90];
  strcpy(this->publisher, publisher);
  this->rating = rating;
}

int videoGame:: getRating(){
  return rating;
}

char* videoGame:: getPublisher(){
  return publisher;
}

void videoGame:: printStuff(){
  cout << this->getTitle();
  cout << this->getYear();
  cout << this->getRating();
  cout << this->getPublisher();
}

