//This is the Video Games cpp file

#include <iostream>
#include <cstring>
#include "dmedia.h"
#include "vgames.h"

using namespace std; 

vgames::vgames() {

}

char* vgames::getPublisher() {
	return publisher; 
}

int* vgames::getRating() {
	return &rating;
}

int vgames::getType() {
	return 0;
}

