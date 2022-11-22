//This is the Parent Class Digital Media

#ifndef mediah
#define mediah

#include <iostream>
#include <cstring>

using namespace std;

class dmedia {

	public:
		dmedia();
		char* getTitle();
		int* getYear();
		virtual int getType();

	private:
		char title[30];
		int year;

};

#endif

