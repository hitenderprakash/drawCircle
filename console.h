/*get console properties
 Hitender Prakash
 Date : Feb 17, 2018
 Returns the size of the current console (will only work for linux)
 return a console object

 This feature will
*/
#ifndef _CONSOLE_H
#define _CONSOLE_H

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
