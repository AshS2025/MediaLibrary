#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

//constructor
//copies info entered in main into new movie obj
movie::movie(char* title, int year, char* director, int rating, float duration) : Parent(year, title){
  this->director = new char[90];
  strcpy(this->director, director);
  this->rating = rating;
  this->duration = duration;
}

//returns rating
int movie:: getRating(){
  return rating;
}

//returns director
char* movie:: getDirector(){
  return director;
}

//returns duration
float movie:: getDuration(){
  return duration;
}

//prints movie fields
//called when obj in vector is a movie and program needs to print information
void movie:: printStuff(){
  cout << "Type: MOVIE" << endl;
  cout << "Title: " << this->getTitle() << endl;
  cout << "Year: " << this->getYear() << endl;
  cout << "Rating out of 10: " << this->getRating() << endl;
  cout << "Director: " << this->getDirector() << endl;
  cout << "Duration: " << this->getDuration() << endl;
  cout << " " << endl;
}

//destructor for movie type
movie::~movie(){
   delete director;
}
