#include <iostream>
#include <vector>
#include <cstring>

#include "dmedia.h"
#include "movies.h"
#include "vgames.h"
#include "music.h"

using namespace std;

int main() {
	bool play = true;
	char title[30];
	int year;

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
			cout << "add";
		}
		else if (strcmp(str, "DELETE") == 0) {
			cout << "del";
		}
		else if (strcmp(str, "SEARCH") == 0) {	
			cout << "serarch";
		}
		else if (strcmp(str, "QUIT") == 0) {
			play = false;	
		}
		else {
			cout << "Invalid Input" << endl;
		}
	}
}
