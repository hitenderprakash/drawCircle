/*get console properties
 Hitender Prakash
 Date : Feb 17, 2018
 Returns number of chars that can be printed on current console
 return a console object
*/
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "console.h"

using namespace std;

console::console(){
    //default initialization
    dimX=100;dimY=100;

    struct winsize _console;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &_console);

    try{
        dimX=_console.ws_col;
        dimY=_console.ws_row;
    }
    catch(const std::exception& e){
        //dimX=100;dimY=100;
    }
}

int console::getConsoleRows(){
    return dimY;
}
int console::getConsoleCols(){
    return dimX;
}
