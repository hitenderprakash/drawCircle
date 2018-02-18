/*get console properties
 Hitender Prakash
 Date : Feb 17, 2018
 Returns the size of the current console
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
