//This is the Child Class Video Games

#include <iostream>
#include "dmedia.h"

using namespace std;

class vgames : public dmedia {

	public:
		vgames();
		int getPublisher();
		int getRating();
	private:
		char* publisher;
		int rating;

};

