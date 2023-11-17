#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

//constructor
//uses info entered in main and copies them into the created object
music::music(char* title, int year, char* artist, float duration, char* publisher) : Parent(year, title){
  this->artist = new char[90];
  strcpy(this->artist, artist);
  this->duration = duration;
  this->publisher = new char[90];
  strcpy(this->publisher, publisher);
}

//returns artist
char* music:: getArtist(){
  return artist;
}

//returns duration 
float music:: getDuration(){
  return duration;
}

//returns publisher
char* music:: getPublisher(){
  return publisher;
}

//prints all fields of music
//this is called when virtual parent print function is called and the obj type is music
void music:: printStuff(){
  cout << "Type: MUSIC" << endl;
  cout << "Title: " << this->getTitle() << endl;
  cout << "Year: " << this->getYear() << endl;
  cout << "Artist: " << this->getArtist() << endl;
  cout << "Publisher: " << this->getPublisher() << endl;
  cout << "Duration: " << this->getDuration() << endl;
  cout << " " << endl;
  }

music:: ~music(){ //destructor
  delete artist;
  delete publisher;
}
