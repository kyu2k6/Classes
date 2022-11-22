#ifndef moviesh
#define moviesh

#include <iostream>
#include <cstring>
#include "dmedia.h"

using namespace std;

class movies : public dmedia {
	public:
		movies();
		virtual int getType();
		char* getDirector();  
		int* getDuration(); 
		float* getRating(); 
	private:
		char director[30]; 
		int duration; 
		float rating; 
};

#endif

