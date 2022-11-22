//This is where most ur code goes and u program what the class does

#include <iostream>
#include <cstring>
#include "dmedia.h"

using namespace std;

dmedia::dmedia() {
}

char* dmedia::getTitle() {
	return title; 
}

int* dmedia::getYear() {
	return &year; 
}

int dmedia::getType() {
	return 0;
}

