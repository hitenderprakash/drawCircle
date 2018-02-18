/*get console properties
 Hitender Prakash
 Date : Feb 17, 2018
 Returns number of chars that can be printed on current console
 credit: https://stackoverflow.com/questions/6812224/getting-terminal-size-in-c-for-windows
*/

#include <iostream>
#include "console.h"

//just in case the import of these linux specific header files fail on Windows
//including them only for Linux
#ifdef __linux__
    #include <sys/ioctl.h>
    #include <stdio.h>
    #include <unistd.h>
#elif _WIN32
    #include <windows.h>
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

    #elif _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int ret = GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi);
        if(ret){
            dimX=csbi.dwSize.X;
            dimY=csbi.dwSize.Y;
        }
    #endif
}

int console::getConsoleRows(){
    return dimY;
}
int console::getConsoleCols(){
    return dimX;
}
