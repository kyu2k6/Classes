#ifndef musich
#define musich


#include <iostream>
#include <cstring>
#include "dmedia.h"

using namespace std;

class music : public dmedia {
	public:
		music();
		virtual int getType();
		char* getArtist();
		char* getPublisher(); 
		int* getDuration(); 
	private:
		char artist[30]; 
		char publisher[30]; 
		int duration; 
};

#endif

