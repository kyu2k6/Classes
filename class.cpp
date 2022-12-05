//Kevin Yu
//12-2-2022
//Categorize medias into video games, movies, or music
//Got help from Nathan Zou

#include <iostream>
#include <vector>
#include <cstring>

#include "dmedia.h"
#include "movies.h"
#include "vgames.h"
#include "music.h"

using namespace std;

void add(vector<dmedia*>* media);
void del(char* Title, vector<dmedia*>* media); // with title
void del(int Year, vector<dmedia*>* media); // with year
void search(char* Title, vector<dmedia*>* media); // with title
void search(int Year, vector<dmedia*>* media); // with year

int main() {
        bool play = true;
        char title[30];
        int year;
        char input[10];

        //storage for all the media files
        vector<dmedia*> storage;

        while (play == true) {

                //Gets add or delete or search or quit
                char str[10];

                cout << "Input: ADD, SEARCH, DELETE, or QUIT: ";
                cin.get(str, 10);
                cin.get();

                //Checks if add or delete or search or quit
                if (strcmp(str, "ADD") == 0) {
                        add(&storage);
                }
                else if (strcmp(str, "DELETE") == 0) {
                        cout << "Delete by Title or Year? ";
                        cin.get(input, 10);
                        cin.get();
                        if (strcmp(input, "Title") == 0) {
                                cout << "Title: ";
                                cin.get(title, 30);
                                cin.get();
                                del(title, &storage);
                        }
                        else if (strcmp(input, "Year") == 0) {
                                cout << "Year: ";
                                cin >> year;
                                cin.clear();
                                cin.ignore(10000, '\n');
                                del(year, &storage);
                        }
                }
                else if (strcmp(str, "SEARCH") == 0) {
                        cout << "Search by Title or Year? ";
                        cin.get(input, 6);
                        cin.get();
                        if (strcmp(input, "Title") == 0) {
                                cout << "Title: ";
                                cin.get(title, 30);
                                cin.get();
                                search(title, &storage);
                        }
                        else if (strcmp(input, "Year") == 0) {
                                cout << "Year: ";
                                cin >> year;
                                cin.clear();
                                cin.ignore(10000, '\n');
                                search(year, &storage);
                        }
                }
                else if (strcmp(str, "QUIT") == 0) {
                        play = false;
                }
                else {
                        cout << "Invalid Input" << endl;
                }
        }

        return 0;
}

void add(vector<dmedia*>* media) {
        char type[30];
        cout << "Are you adding Movies, Music, or Videogames? ";
        cin.get(type, 30);
        cin.get();
        if (strcmp(type, "Movies") == 0) {
                movies* movie = new movies();
                cout << "Title? ";
                cin.get(movie->getTitle(), 30);
                cin.get();
                cout << "Year? ";
                cin >> *movie->getYear();
                cin.get();
                cout << "Director? ";
                cin.get(movie->getDirector(), 30);
                cin.get();
                cout << "Duration(minutes)? ";
                cin >> *movie->getDuration();
                cin.get();
                cout << "Rating out of 5 stars: ";
                cin >> *movie->getRating();
                cin.get();
                media->push_back(movie);
        }
        else if (strcmp(type, "Music") == 0) {
                music* muse = new music();
                cout << "Title? ";
                cin.get(muse->getTitle(), 30);
                cin.get();
                cout << "Artist? ";
                cin.get(muse->getArtist(), 30);
                cin.get();
                cout << "Publisher? ";
                cin.get(muse->getPublisher(), 30);
                cin.get();
                cout << "Duration(seconds)? ";
                cin >> *muse->getDuration();
                cin.get();
                cout << "Year? ";
                cin >> *muse->getYear();
                cin.get();
                media->push_back(muse);
        }
        else if (strcmp(type, "Videogames") == 0) {
                vgames* vg = new vgames();
                cout << "Title? ";
                cin.get(vg->getTitle(), 30);
                cin.get();
                cout << "Year? ";
                cin >> *vg->getYear();
                cin.get();
                cout << "Publisher: ";
                cin.get(vg->getPublisher(), 30);
                cin.get();
                cout << "Rating out of 5 stars: ";
                cin >> *vg->getRating();
                cin.get();
                media->push_back(vg);

        }
        else {
                cout << "Invalid media type" << endl;
        }
}
void del(char* Title, vector<dmedia*>* media) { //Delete with title
    char input[5];
    vector<dmedia*>::iterator iterDelTtl;
    for (iterDelTtl = media->begin(); iterDelTtl != media->end(); ++iterDelTtl) {
        if (strcmp(Title, (*iterDelTtl)->getTitle()) == 0) {
            cout << (*iterDelTtl)->getTitle() << ", ";
            cout << *(*iterDelTtl)->getYear() << endl;
            if ((*iterDelTtl)->getType() == 0) { //videogames
                cout << "  Videogame: " << endl;
                cout << "  Published by " << dynamic_cast<vgames*>(*iterDelTtl)->getPublisher() << endl;
                cout << *dynamic_cast<vgames*>(*iterDelTtl)->getRating() << " stars" << endl;
            }
            else if ((*iterDelTtl)->getType() == 1) { //music
                cout << "  Music: " << endl;
                cout << "  Artist was " << dynamic_cast<music*>(*iterDelTtl)->getArtist() << endl;
                cout << "  Duration of " << *dynamic_cast<music*>(*iterDelTtl)->getDuration() << " seconds" << endl;
                cout << "  Published by " << dynamic_cast<music*>(*iterDelTtl)->getPublisher() << endl << endl;
            }
            else if ((*iterDelTtl)->getType() == 2) { //movies
                cout << "  Movie: " << endl;
                cout << "  Directed by " << dynamic_cast<movies*>(*iterDelTtl)->getDirector() << endl;
                cout << "  Duration of " << *dynamic_cast<movies*>(*iterDelTtl)->getDuration() << " minutes" << endl;
                cout << *dynamic_cast<movies*>(*iterDelTtl)->getRating() << " stars" << endl << endl;
            }
            cout << "Delete this media? 'yes' or 'no'" << endl;
            cin.get(input, 5);
            cin.get();
            if (strcmp(input, "yes") == 0) { //delete
                delete* iterDelTtl;
                iterDelTtl = media->erase(iterDelTtl);
                return;
            }
        }
    }
}

void del(int Year, vector<dmedia*>* media) { //Delete with year
    char input[5];
    vector<dmedia*>::iterator iterDelYr;
    for (iterDelYr = media->begin(); iterDelYr != media->end(); ++iterDelYr) {
        if (Year == *(*iterDelYr)->getYear()) {
            cout << (*iterDelYr)->getTitle() << ", ";
            cout << *(*iterDelYr)->getYear() << endl;
            if ((*iterDelYr)->getType() == 0) {
                cout << "  Videogame: " << endl;
                cout << "  Published by " << dynamic_cast<vgames*>(*iterDelYr)->getPublisher() << endl;
                cout << *dynamic_cast<vgames*>(*iterDelYr)->getRating() << " stars" << endl;
            }
            else if ((*iterDelYr)->getType() == 1) {
                cout << "  Music: " << endl;
                cout << "  Artist was " << dynamic_cast<music*>(*iterDelYr)->getArtist() << endl;
                cout << "  Duration of " << *dynamic_cast<music*>(*iterDelYr)->getDuration() << " seconds" << endl;
                cout << "  Published by " << dynamic_cast<music*>(*iterDelYr)->getPublisher() << endl << endl;
            }
            else if ((*iterDelYr)->getType() == 2) {
                cout << "  Movie: " << endl;
                cout << "  Directed by " << dynamic_cast<movies*>(*iterDelYr)->getDirector() << endl;
                cout << "  Duration of " << *dynamic_cast<movies*>(*iterDelYr)->getDuration() << " minutes" << endl;
                cout << *dynamic_cast<movies*>(*iterDelYr)->getRating() << " stars" << endl << endl;
            }
            cout << "Delete this media? 'yes' or 'no'" << endl;
            cin.get(input, 5);
            cin.get();
            if (strcmp(input, "yes") == 0) {
                delete* iterDelYr;
                iterDelYr = media->erase(iterDelYr);
                return;
            }
        }
    }
}                                               

void search(char* Title, vector<dmedia*>* media) { //Search with title
    vector<dmedia*>::iterator iterSerTtl;
    for (iterSerTtl = media->begin(); iterSerTtl != media->end(); ++iterSerTtl) {
        if (strcmp(Title, (*iterSerTtl)->getTitle()) == 0) {
            cout << (*iterSerTtl)->getTitle() << ", ";
            cout << *(*iterSerTtl)->getYear() << endl;
            if ((*iterSerTtl)->getType() == 0) {
                cout << "  Published by " << dynamic_cast<vgames*>(*iterSerTtl)->getPublisher() << endl;
                cout << *dynamic_cast<vgames*>(*iterSerTtl)->getRating() << " stars" << endl;

            }
            else if ((*iterSerTtl)->getType() == 1) {
                cout << "  Artist was " << dynamic_cast<music*>(*iterSerTtl)->getArtist() << endl;
                cout << "  Duration of " << *dynamic_cast<music*>(*iterSerTtl)->getDuration() << " seconds" << endl;
                cout << "  Published by " << dynamic_cast<music*>(*iterSerTtl)->getPublisher() << endl << endl;
            }
            else if ((*iterSerTtl)->getType() == 2) {
                cout << "  Directed by " << dynamic_cast<movies*>(*iterSerTtl)->getDirector() << endl;
                cout << "  Duration of " << *dynamic_cast<movies*>(*iterSerTtl)->getDuration() << " minutes" << endl;
                cout << *dynamic_cast<movies*>(*iterSerTtl)->getRating() << " stars" << endl << endl;
            }
        }
    }
}

void search(int Year, vector<dmedia*>* media) { //Search with year
    vector<dmedia*>::iterator iterSerYr;
    for (iterSerYr = media->begin(); iterSerYr != media->end(); ++iterSerYr) {
        if (Year == *(*iterSerYr)->getYear()) {
            cout << (*iterSerYr)->getTitle() << ", ";
            cout << *(*iterSerYr)->getYear() << endl;
            if ((*iterSerYr)->getType() == 0) {
                cout << "  Published by " << dynamic_cast<vgames*>(*iterSerYr)->getPublisher() << endl;
                cout << *dynamic_cast<vgames*>(*iterSerYr)->getRating() << " stars" << endl;
            }
            else if ((*iterSerYr)->getType() == 1) {
                cout << "  Artist was " << dynamic_cast<music*>(*iterSerYr)->getArtist() << endl;
                cout << "  Duration of " << *dynamic_cast<music*>(*iterSerYr)->getDuration() << " seconds" << endl;
                cout << "  Published by " << dynamic_cast<music*>(*iterSerYr)->getPublisher() << endl << endl;
            }
            else if ((*iterSerYr)->getType() == 2) {
                cout << "  Directed by " << dynamic_cast<movies*>(*iterSerYr)->getDirector() << endl;
                cout << "  Duration of " << *dynamic_cast<movies*>(*iterSerYr)->getDuration() << " minutes" << endl;
                cout << *dynamic_cast<movies*>(*iterSerYr)->getRating() << " stars" << endl << endl;
            }
        }
    }
}











                                                                                                                                                            254,11        Bot
