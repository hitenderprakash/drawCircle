/*get console properties
 Hitender Prakash
 Date : Feb 17, 2018
 Returns number of chars that can be printed on current console
 return a console object

*/
#ifndef _CONSOLE_H
#define _CONSOLE_H

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class console{
	private:
	int dimX;
	int dimY;

	public:
	console();
	int getConsoleRows();
	int getConsoleCols();
};
#endif
