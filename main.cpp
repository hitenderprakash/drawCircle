/*
file: main.cpp
Driver code for Raster class functionality
Program to draw a circle on text console without floating point operation
Hitender Prakash
Date: Feb 17, 2018
*/
#include <iostream>
#include <vector>
#include "Raster.h"
#include "console.h"
using namespace std;

int main(){

    //test code to get console properties
    //by this way we can make circle always fit the screen
    // screen may have any size
    //resizing the screen after rendering may change the graphics
    console c;
    int cols=c.getConsoleCols()/2; //2 pixels along x-axis
    int rows=c.getConsoleRows();

    Raster circle(cols, rows);
    circle.set_circle_param(cols/2,rows/2,min(cols,rows)/2-1);
    circle.drawCircle();
    circle.dispay_Circle();

    //test resize dimensions
    //circle.resize_RasterDimensions(20,16);
    //circle.dispay_Circle();

    //test center relocation
    //circle.relocate_Center(10,8);
    //circle.dispay_Circle();

    return 0;
}
