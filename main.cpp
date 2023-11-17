#include <iostream>
#include "Parent.h"
#include "videoGame.h"
#include "movie.h"
#include "music.h"
#include <cstring>
#include <vector>

using namespace std;

//function prototypes
void addVideoGame(vector<Parent*>&media);
void addMovie(vector<Parent*>&media);
void addMusic(vector<Parent*>&media);
void searchMedia(vector<Parent*>&media);
void deleteMedia(vector<Parent*>&media);

bool playing = true;

//main function
//functionality: allows users to add, search, or delete media and calls the appropriate classes/functions
int main (){
  vector<Parent*> media;
  cout << "type 'av' to add videogame" << endl;
  cout << "type 'amo' to add movie" << endl;
  cout << "type 'amu' to add music" << endl;
  cout << "type 's' to search library and 'd' to delete an object and 'q' to quit" << endl;

  while (playing){
    cout << "what do you want to do" << endl;
    char action[5];
    cin.getline(action, 5);

    if (strcmp (action, "av") == 0){
      addVideoGame(media);
    }

    else if (strcmp (action, "amo") == 0){
      addMovie(media);
    }

    else if (strcmp(action, "amu") == 0){
      addMusic(media);
    }

    else if (strcmp(action, "s") == 0){
      searchMedia(media);
    }

    else if (strcmp(action, "d") == 0){
      deleteMedia(media);
    }

    else if (strcmp(action, "q") == 0){
      playing = false;
    }
    
  }
 
}

//prompts user to enter information for a video game and then passes that info into the videogame file to create a new object.
//pointer for that object is pushed into the parent vector
void addVideoGame (vector<Parent*>&media){
  cout << "you are now entering info for a VIDEOGAME" << endl;
  cout << "enter title" << endl;
  char title[100];
  cin.getline(title, 100);
  cout << "enter year" << endl;
  int year;
  cin >> year;
  cin.ignore (10, '\n');
  cout << "enter rating. whole number from 1-10" << endl;
  int rating;
  cin >> rating;
  cin.ignore (10, '\n');
  cout << "enter publisher" << endl;
  char publisher[100];
  cin.getline(publisher, 100);
  videoGame* vg = new videoGame (title, year, rating, publisher);

  media.push_back(vg);

}


//same functionality as videoGame function but with different variables as per the requirements for a movie
//made a new function for simplicity (aka i hate nested loops)
void addMovie (vector<Parent*>&media){
  cout << "enter title" << endl;
  char title[100];
  cin.getline(title, 100);
  cout << "enter year" << endl;
  int year;
  cin >> year;
  cin.ignore (10, '\n');
  cout << "enter rating, whole number from 1-10" << endl;
  int rating;
  cin >> rating;
  cin.ignore(10, '\n');
  cout << "enter director" << endl;
  char director[90];
  cin.getline(director, 100);
  cout << "enter duration as a decimal to one place" << endl;
  float duration;
  cin >> duration;
  cin.ignore(10, '\n');
  movie* mv = new movie (title, year, director, rating, duration);

  media.push_back(mv);
}

//again same function as addVideoGame and addMovie but with the fields required for music
void addMusic(vector<Parent*>&media){
  cout << "enter title" << endl;
  char title[100];
  cin.getline(title, 100);
  cout << "enter year" << endl;
  int year;
  cin >> year;
  cin.ignore (10, '\n');
  cout << "enter artist" << endl;
  char artist[90];
  cin.getline(artist, 100);
  cout << "enter duration as a decimal to one place" << endl;
  float duration;
  cin >> duration;
  cin.ignore(10, '\n');
  cout << "enter publisher" << endl;
  char publisher[100];
  cin.getline(publisher, 100);
  music* ms = new music(title, year, artist, duration, publisher);

  media.push_back(ms);
}

//allows user to search for media and then lists all objects that match user request
void searchMedia (vector<Parent*>&media){
  cout << "do you want to search by title or year? (type t or y)" << endl;
  char input;
  cin >> input;
  cin.ignore(10, '\n');
  if (input == 'y'){ //search by year
    int findId;
    cout << "type the year of media you want to find" << endl;
    cin >> findId;
    cin.ignore(5, '\n');
    for (vector<Parent*> :: iterator it = media.begin(); it != media.end(); it++){
      if ((*it)->getYear() == findId){ //if the year entered matches the year of an object in the vector, list it!
	//call virtual parent print stuff function
	(*it)->printStuff();
      }
    }
  }
  if (input == 't'){ //same as search by year but with a char array instead of an int
    char input[100];
    cout << "type the title of the media you want to find" << endl;
    cin >> input;
    cin.ignore(10, '\n');
    for (vector<Parent*> :: iterator it = media.begin(); it != media.end(); it++) {
      if (strcmp(input, ((*it)->getTitle())) == 0){
	(*it)->printStuff();
      }
    }
  }

}
    
// user can delete media by entering its year or title
  void deleteMedia (vector<Parent*>&media){
    cout << "do you want to delete by title or year? (type t or y)" << endl;
    char input;
    cin >> input;
    cin.ignore(10, '\n');
    if (input == 'y'){
      int findId; //this part has the same functionality as the search function
      cout << "type the year of the media you want to delete" << endl;
      cin >> findId;
      cin.ignore(10, '\n');
      for (vector<Parent*> :: iterator it = media.begin(); it != media.end(); it++){
	if ((*it)->getYear() == findId){
	  (*it)->printStuff(); //prints all info of the matching obj
	  cout << "do you want to delete this? y or n." << endl; //requires user confirmation
	  char choice;
	  cin >> choice;
	  cin.ignore (5, '\n');
	  if (choice == 'y'){
	    delete(*it); //delete obj
	    media.erase(it); //remove from vector
	    return; //reset vector
	  }
	}
      }
    }

    if (input == 't'){ //same as by year but with char array
      char findT[100];
      cout << "type the title of the media you want to delete" << endl;
      cin.getline(findT, 100);
      for (vector<Parent*> :: iterator it = media.begin(); it != media.end(); it++){
	if (strcmp(((*it)->getTitle()), findT) == 0){
	  (*it)->printStuff();
	  cout << "do you want to delete this? y or n." << endl;
	  char choice;
	  cin >> choice;
	  cin.ignore (5, '\n');
	  if (choice == 'y'){
	    delete (*it); //calls destructor 
	    media.erase(it); //removes from vector
	    return; //resets vector
	  }
	}

      }
    }
  }
