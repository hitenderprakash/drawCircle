/*get console properties
 Hitender Prakash
 Date : Feb 17, 2018
 Returns number of chars that can be printed on current console
 credit: https://stackoverflow.com/questions/6812224/getting-terminal-size-in-c-for-windows
*/

#include <iostream>
#include "console.h"

//just in case the import of these linux/Windows based on plateform the code is compiled for
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
    dimX=50;dimY=50;
    #ifdef __linux__
        try{
            struct winsize _console;
            ioctl(STDOUT_FILENO, TIOCGWINSZ, &_console);
            dimX=_console.ws_col;
            dimY=_console.ws_row;
        }
        catch(const std::exception& e){
            //dimX=50;dimY=50;
        }

    #elif _WIN32
            try{
                CONSOLE_SCREEN_BUFFER_INFO csbi;
                int ret = GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi);
                if(ret){
                    dimX=csbi.srWindow.Right - csbi.srWindow.Left + 1;
                    dimY=csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
                }
            }
            catch(const std::exception& e){
                //dimX=50;dimY=50;
            }
    #endif
}

int console::getConsoleRows(){
    return dimY;
}
int console::getConsoleCols(){
    return dimX;
}
