#include <iostream>
#include <cstring>
#include "videoGame.h"

using namespace std;

//constructor
//uses entered information and copies into new vg obj
//uses parent functions for title and year
videoGame::videoGame(char* title, int year, int rating, char* publisher): Parent(year, title){
  this->publisher = new char[90];
  strcpy(this->publisher, publisher);
  this->rating = rating;
}

//gets and returns rating
int videoGame:: getRating(){
  return rating;
}

//gets and returns publisher
char* videoGame:: getPublisher(){
  return publisher;
}

//prints videogame specific fields
//called when need to print and obj is videogame
void videoGame:: printStuff(){
  cout << "Type: VIDEOGAME" << endl;
  cout << "Title: " << this->getTitle() << endl;
  cout << "Year: " << this->getYear() << endl;
  cout << "Rating out of 10: " << this->getRating() << endl;
  cout << "Publisher: " << this->getPublisher() << endl;
  cout << " " << endl;
}

//videogame destructor
videoGame::~videoGame(){
  delete publisher;
}

