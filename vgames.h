#ifndef vgamesh
#define vgamesh


#include <iostream>
#include <cstring>
#include "dmedia.h"

using namespace std;

class vgames : public dmedia {

	public:
		vgames();
		virtual int getType();
		char* getPublisher();
		int* getRating();
	private:
		char publisher[30];
		int rating;

};

#endif

