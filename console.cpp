/*get console properties
 Hitender Prakash
 Date : Feb 17, 2018
 Returns number of chars that can be printed on current console
 return a console object
*/

#include <iostream>
#include "console.h"

//just in case the import of these linux specific header files fail on Windows
//including them only for Linux
#ifdef __linux__
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#endif

using namespace std;

console::console(){
    //default initialization
    dimX=100;dimY=100;
    #ifdef __linux__
        try{
            struct winsize _console;
            ioctl(STDOUT_FILENO, TIOCGWINSZ, &_console);
            dimX=_console.ws_col;
            dimY=_console.ws_row;
        }
        catch(const std::exception& e){
            //dimX=100;dimY=100;
        }
    #endif
}

int console::getConsoleRows(){
    return dimY;
}
int console::getConsoleCols(){
    return dimX;
}
